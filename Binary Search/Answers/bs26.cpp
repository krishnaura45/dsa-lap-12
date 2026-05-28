// Median of two sorted arrays of different sizes
#include<bits/stdc++.h>
using namespace std;

// Brute 
double median_of_two_sorted_arrays(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();
    // vector<int> arr(n1+n2,0);
    // for(int i=0;i<n1;i++){
    //     arr[i]=a[i];
    // }
    // for(int i=0;i<n2;i++){
    //     arr[i+n1]=b[i];
    // }

    // sort(arr.begin(),arr.end());

    vector<int> arr;
    int i=0,j=0;   // two pointers for merge sort type merging
    while(i<n1 && j<n2){
        if(a[i]<b[j]) arr.push_back(a[i++]);
        else arr.push_back(b[j++]);
    }
    while(i<n1) arr.push_back(a[i++]);
    while(j<n2) arr.push_back(b[j++]);

    if((n1+n2)%2==1) return (double)arr[(n1+n2)/2];
    return (double)(arr[(n1+n2)/2]+arr[(n1+n2-1)/2])/2;
}
// O(N+NlogN),N=>n1+n2 ==> O(N),O(N)

// Better 
double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1 && (ind1el==-1 || ind2el==-1)) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2 && (ind1el==-1 || ind2el==-1)) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)(ind1el + ind2el) / 2.0;
}
// O(N),O(1)

// Optimal
// First try to solve for even number of elements and then switch to odd
// We will try to formulate the left half, simultaneously checking for valid symmetry
// Summarising two points :
// 1. BS will be on the basis of symmetry where we determine how many elements will be from array 1 and how many will be from array 2
// 2. For valid symmetry, we need to check criss cross inequality, for eg in following case-
// 1 2 4 | 7 10 12
//   2 3 | 6 15
// i.e. 4<6 and 3<7 is correct symmetry condition
double median_bs(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();

    // assuming the first array to be smaller in size
    if(n1>n2) return median_bs(b,a);
    int n=(n1+n2);
    int low=0,high=n1;
        while(low<=high){
            int mid1=(low+high)/2;   // how many elements from smaller array will be needed to formulate left & right half
            int mid2=(n+1)/2-mid1;

            // assigning l1,l2,r1,r2 in case they are not present
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;

            if(mid1<n1) r1=a[mid1];   // to ensure that mid1 exists or not
            if(mid2<n2) r2=b[mid2];   // to ensure that mid2 exists or not
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];

            if(l1>r2)
             // eliminate right half
             high=mid1-1;
            else if(l2>r1)
             // eliminate left half
             low=mid1+1;
            else{
               if(n%2==1) return (double)max(l1,l2);
               else return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
        }
    return -1.0;
}
// O(log2 (min(n1,n2)))

int main(){
    vector<int> arr1={1,3,4,7,10,12};
    vector<int> arr2={2,3,15};
    // double ans=median_of_two_sorted_arrays(arr1,arr2);
    // double ans=median(arr1,arr2);
    double ans=median_bs(arr1,arr2);
    cout<<ans;
    return 0;
}
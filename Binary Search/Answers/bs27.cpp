// Kth element of two sorted arrays
#include<bits/stdc++.h>
using namespace std;

// Brute 
int kth_element_of_two_sorted_arrays(vector<int> a,vector<int> b,int k){
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

    return arr[k-1];
}
// O(N+NlogN),N=>n1+n2 ==> O(N),O(N)

// Better 
int kth_element(vector<int> a, vector<int> b,int k) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    int cnt = 0;
    int el=-1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            cnt++;
            if (cnt == k) el = a[i];
            i++;
        }
        else {
            cnt++;
            if (cnt == k) el = b[j];
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1 && (el==-1)) {
        cnt++;
        if (cnt == k) el = a[i];
        i++;
    }
    while (j < n2 && (el==-1)) {
        cnt++;
        if (cnt == k) el = b[j];
        j++;
    }

    return el;
}
// O(N),O(1)

// Optimal
// Similar approach as for previous problem except few changes
int kth_element_bs(vector<int> a,vector<int> b,int n1,int n2,int k){
    if(k>=max(n1,n2)){
        // assuming the first array to be bigger in size
        if(n2>n1) return kth_element_bs(b,a,n2,n1,k);
        int low=max(0,k-n1),high=min(k,n2);
        while(low<=high){
            int mid2=(low+high)/2;   // how many elements from smaller array will be needed to formulate left & right half
            int mid1=k-mid2;

            // assigning l1,l2,r1,r2 
            int l1 = mid1 == 0 ? INT_MIN : a[mid1 - 1]; 
            int l2 = mid2 == 0 ? INT_MIN : b[mid2 - 1];
            int r1 = mid1 == n1 ? INT_MAX : a[mid1]; 
            int r2 = mid2 == n2 ? INT_MAX : b[mid2]; 

            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1; 
            }
        }
    }
    else{
        if(n1 > n2) {
            return kth_element_bs(b, a, n2, n1, k); 
        }
            
        int low = max(0,k-n1), high = min(k,n2);
            
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1];
            int r1 = cut1 == n2 ? INT_MAX : a[cut1]; 
            int r2 = cut2 == n1 ? INT_MAX : b[cut2]; 
                
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1; 
            }
        }
    }
    return -1;
}
// O(log2 (min(n1,n2)))

int main(){
    vector<int> arr1={1,3,4,7,10,12};
    vector<int> arr2={2,3,15};
    int k=8;    // 2,5,6,8
    // int ans=kth_element_of_two_sorted_arrays(arr1,arr2,k);
    // int ans=kth_element(arr1,arr2,k);
    int ans=kth_element_bs(arr1,arr2,arr1.size(),arr2.size(),k);
    cout<<ans;
    return 0;
}
// Find inversions in two sorted arrays --> Intution behind h9 / Add on problem
#include<bits/stdc++.h>
using namespace std;

// brute
int sortedInversions(vector<int> &arr1,vector<int> &arr2){
    int cnt=0;
    int n1=arr1.size();
    int n2=arr2.size();
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(arr1[i]>arr2[j]) cnt++;
        }
    }
    return cnt;
}
// O(n1*n2),O(1)

// Optimal
int sortedInversions_op(vector<int> &arr1,vector<int> &arr2){
    int cnt=0;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0,j=0;  // left and right pointers
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            i++;
        }
        else if(arr1[i]>arr2[j]){
            cnt+= (n1-i);
            j++;
        }
    }
    return cnt;
}
// O(n1+n2),O(1)

int main(){
    vector<int> a1={2,3,5,6};
    vector<int> a2={2,2,4,4,8};
    // int ans=sortedInversions(a1,a2);
    int ans=sortedInversions_op(a1,a2);
    cout<<ans;
    return 0;
}
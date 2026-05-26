// Single Element in Sorted Array
#include<bits/stdc++.h>
using namespace std;

// Brute 
int seisa(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i==0){
            if(arr[i]!=arr[i+1]) return arr[i];
        }

        else if(i==n-1){
            if(arr[i]!=arr[i-1]) return arr[i];
        }

        else{
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1]) return arr[i];
        }
    }
    return -1;
}

// Binary Search --> all about elimination
// We need to find a property of single element or observe array carefully
int seisa_bs(vector<int> arr){
    int n=arr.size();
    if(n==1) return arr[0];
    // Covering the edge cases
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-2]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid=low+(high-low)/2;

        // If the middle one is the required single element
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];

        // If we are on right half & element is on left half
        if((mid%2==0 && arr[mid]==arr[mid-1]) || (mid%2==1 && arr[mid]==arr[mid+1])){
            // eliminate right half
            high=mid-1;
        }

        // If we are on left half & element is on right half
        else{
            // eliminate left half
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={1,1,2,2,3,3,4,5,5,6,6};
    // int ans=seisa(arr);
    int ans=seisa_bs(arr);
    cout<<ans;
    return 0;
}
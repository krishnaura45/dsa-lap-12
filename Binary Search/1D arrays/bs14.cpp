// Find the peak element
#include<bits/stdc++.h>
using namespace std;

// Brute --> Linear search
int find_peak(vector<int> arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])){
            return arr[i];
        }
    }
    return -1;
}

// Optimal --> Binary search application
// 1 peak 
//       *
//     *   *
//   *       *
int find_peak_bs(vector<int> arr){
    int n=arr.size();

    // Covering edge cases
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        // when middle one is the peak
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];
        
        // when middle one is on increasing slope
        else if(arr[mid]<arr[mid+1]) 
         // peak will always be on right
         low=mid+1;
        
        // when middle one is on decreasing slope
        else if(arr[mid]<arr[mid-1]) 
         // peak will always be on left
         high=mid-1;
    }
    return -1;
}

// >1 peak
//       *
//     *   *   *
//   *       *   *
int find_peak_bsm(vector<int> arr){
    int n=arr.size();

    // Covering edge cases
    if(arr[0]>arr[1]) return arr[0];
    if(arr[n-1]>arr[n-2]) return arr[n-1];

    int low=1,high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        // when middle one is one of the peaks
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return arr[mid];
        
        // when middle one is on increasing slope
        else if(arr[mid]<arr[mid+1]) 
         // atleast one peak will always be on right
         low=mid+1;
        
        // when middle one is on decreasing slope
        else
         // atleast one peak will always be on left
         high=mid-1;
    }
    return -1;
}

int main(){
    vector<int> arr1={1,2,3,4,5,6,7,8,5,1};
    vector<int> arr2={1,2,1,5,3};
    // int ans=find_peak(arr);
    // cout<<ans;

    int ans1=find_peak_bs(arr1);
    int ans2=find_peak_bsm(arr2);
    cout<<"Peak for 1 peak array : "<<ans1<<endl;
    cout<<"Peak for multiple peak array : "<<ans2;
    return 0;
}
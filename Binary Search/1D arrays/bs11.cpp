// Minimum in rotated sorted array (duplicate)
#include<bits/stdc++.h>
using namespace std;

// Brute --> linear search

// Optimal -> Binary search application 
// Key point -->> Trim down the search space
int min_RSA_2(vector<int> arr){
    int n=arr.size();
    int low=0,high=n-1;
    int mini=INT_MAX;
    while(low<=high){
        int mid=(low+high)/2;

        // If search space is already sorted
        if(arr[low]<arr[high]){
            mini=min(mini,arr[low]);
            break;
        }

        if(arr[low]==arr[mid] && arr[mid]==arr[high])
         low=low+1;
         high=high-1;
         continue;

        // **Identifying sorted half**
        // if left is sorted
        if(arr[low]<=arr[mid]){
            mini=min(mini,arr[low]);
            low=mid+1;
        }

        // if right is sorted
        else{
            mini=min(mini,arr[mid]);
            high=mid-1;
        }
    }
    return mini;
}

int main(){
    vector<int> arr={3,1,2,3,3,3,3};
    int ans=min_RSA_2(arr);
    cout<<ans;
}
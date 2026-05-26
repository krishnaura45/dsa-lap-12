// Minimum in rotated sorted array (unique)
#include<bits/stdc++.h>
using namespace std;

// Brute -> Linear search

// Optimal -> Binary search application 
// Key point -->> Identify the sorted half 
int min_RSA(vector<int> arr){
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
    vector<int> arr={7,8,9,10,2,3,4,5,6};
    int ans=min_RSA(arr);
    cout<<"The minimum in rotated sorted array : "<<ans;
}
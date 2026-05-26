// Find out how many times the array has been rotated (unique)
#include<bits/stdc++.h>
using namespace std;

// Brute -> Linear search

// Optimal -> Binary search application 
// Key point -->> Identify the sorted half 
int count_rotations(vector<int> arr){
    int n=arr.size();
    int low=0,high=n-1;
    int mini=INT_MAX;
    int index=-1;  // rotation counter
    while(low<=high){
        int mid=(low+high)/2;
        // If search space is already sorted
        if(arr[low]<arr[high]){
            if(mini>arr[low]){
                mini=arr[low];
                index=low;
            }
            break;
        }

        // if left is sorted
        if(arr[low]<=arr[mid]){
            if(mini>arr[low]){
                mini=arr[low];
                index=low;
            }
            low=mid+1;
        }
        // if right is sorted
        else{
            if(mini>arr[mid]){
                mini=arr[mid];
                index=mid;
            }
            high=mid-1;
        }
    }
    return index;
}

int main(){
    vector<int> arr={7,8,9,10,2,3,4,5,6};
    int ans=count_rotations(arr);
    cout<<"The array has been rotated "<<ans<<" times";
}
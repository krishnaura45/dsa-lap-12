// Search in rotated sorted array - I (Unique elements)
#include<bits/stdc++.h>
using namespace std;

// Brute -> Linear search

// Optimal -> Binary search application 
// Key point -->> Identify the sorted half 
int search_1(vector<int> arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x) return mid;
        
        // Either the left half will be sorted or the other
        // if left is sorted
        if(arr[low]<=arr[mid]){
            // Element lying inside sorted half
            if(arr[low]<=x && x<=arr[mid]) high=mid-1;

            // Element not lying inside sorted half so eliminate it
            else low=mid+1;
        }

        // if right is sorted
        else if(arr[mid]<=arr[high]){
            // Element lying inside sorted half
            if(arr[mid]<=x && x<=arr[high]) low=mid+1;

            // Element not lying inside sorted half so eliminate it
            else high=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr={7,8,9,1,2,3,4,5,6};
    int target=5;  // 1,8,5
    int ans=search_1(arr,target);
    cout<<"The target is at the index : "<<ans;
}
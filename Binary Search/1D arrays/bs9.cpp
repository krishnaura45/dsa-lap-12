// Search in Rotated Sorted Array -II (Duplicate elements)
#include<bits/stdc++.h>
using namespace std;

// Brute -> Linear search

// Optimal -> Binary search application 
// Key point -->> Trim down the search space
bool search_2(vector<int> arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x) return true;

        if(arr[low]==arr[mid] && arr[mid]==arr[high])
         low=low+1;
         high=high-1;
         continue;

        // **Identifying sorted half**
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
    return false;
}

int main(){
    vector<int> arr={3,1,2,3,3,3,3};
    int target=1;  // 1,5,3
    bool ans=search_2(arr,target);
    cout<<ans;
}
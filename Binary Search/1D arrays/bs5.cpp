// Floor and Ceil in sorted array
/*
Floor : largest no. in array <= x  (ground)
Ceil : Smallest no. in array >= x  (top)
*/
// Therefore ceil=arr[lower_bound]

#include <bits/stdc++.h>
using namespace std;

// Optimal --> binary search
int find_floor(vector<int> arr, int x) {
    int n=arr.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] <= x) {
            ans = arr[mid];
            //look on the right for largest
            low = mid + 1;
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return ans;
}

int find_ceil(vector<int> arr, int x) {
    int n=arr.size();
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = arr[mid];
            //look for smallest on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

vector<int> floor_and_ceil(vector<int> arr,int x){
    int floor=find_floor(arr,x);
    int ceil=find_ceil(arr,x);
    return {floor,ceil};
}

int main(){
    vector<int> arr = {2,3,6,7,8,8,11,11,11,12};
    int x = 13;  // 9,1,13 inputs
    
    vector<int> ans = floor_and_ceil(arr,x);
    cout << "The floor is : " << ans[0] << "\n";
    cout << "The ceil is : " << ans[1] << "\n";
    return 0;
}
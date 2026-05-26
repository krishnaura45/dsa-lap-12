// Lower bound of a number
#include <bits/stdc++.h>
using namespace std;

// Brute force --> linear search

// Optimal --> binary search
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
// O(log b2 n)

// stl
int lowerBound_stl(vector<int> arr,int x){
    int ans=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    return ans;
}

int main(){
    vector<int> arr = {2,3,6,7,8,8,11,11,11,12};
    int n = 10, x = 6;
    // int ind = lowerBound(arr, n, x);
    int ind = lowerBound_stl(arr,x);
    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}
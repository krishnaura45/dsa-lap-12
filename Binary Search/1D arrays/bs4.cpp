// Search INSERT position in an array
/*
Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.
*/

// We can solve this problem using the lower-bound algorithm 

#include <bits/stdc++.h>
using namespace std;

// Optimal --> binary search
int searchIP(vector<int> arr,int x) {
    int n=arr.size();
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

int main(){
    vector<int> arr = {2,3,6,7,8,8,11,11,11,12};
    int x = 9;
    int ind = searchIP(arr,x);
    cout << "The insert position shoul be index: " << ind << "\n";
    return 0;
}
// Find kth missing number
// Problem Statement: You are given a strictly increasing array ‘vec’ and a positive integer ‘k’. Find the ‘kth’ positive integer missing from ‘vec’.

#include <bits/stdc++.h>
using namespace std;

// Different from brute, but not the optimal
int missingK(vector<int> arr,int k) {
    int n=arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) k++; //shifting k
        else break;
    }
    return k;
}
// O(n)

int missingK_bs(vector<int> arr,int k){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);   // no. of missing numbers
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high+1+k;  // low+k
}
// ans => arr[high]+more => arr[high]+(k-missing) => k+high+1 as missing = arr[high]-(high+1)
// O(log2 n)

int main()
{
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    // int ans = missingK(arr,k);
    int ans = missingK_bs(arr,k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}
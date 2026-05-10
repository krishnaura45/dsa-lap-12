f// Count subarrays with the given sum
#include<bits/stdc++.h>
using namespace std;

// Brute

// Better --> optimized brute
int numSubarrays(vector<int> &arr,int k){
    int n=arr.size();
    
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                cnt++;
            }
        }
    }
    return cnt;
}

// Optimal -->>> marked
int numSubarrays_op(vector<int> &arr,int k){
    int n = arr.size(); // size of the given array.
    map<int,int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum in the map.
        mpp[preSum] += 1;
    }
    return cnt;
}
// O(n) / O(nlogn) depending on map, O(n)

int main(){
    vector<int> arr={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    //int ans=numSubarrays(arr,k);
    int ans=numSubarrays_op(arr,k);
    cout<<"Number of subarrays with sum "<<k<<" : "<<ans<<endl;
    return 0;    
}
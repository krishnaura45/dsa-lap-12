// Longest Subarray with sum K | [Postives and Negatives]
#include<bits/stdc++.h>
using namespace std;

// Optimized BF --> simplest
int findLongestSubarray_bf(vector<int> &a,int k){
    int n=a.size();
    
    int len=0;  // length variable for longest subarray
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}

// Optimal approach --> using hashmap --->>> marked
int findLongestSubarray(vector<int> &a,long long k){
    int n = a.size(); // size of the array.

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        long long rem = sum - k;

        // If sum equal to x-k exists in the map previously
        if (preSumMap.find(rem) != preSumMap.end()) {
            //Calculate the length and update maxLen:
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        // If the sum x was not there previously, then store
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;   // Finally, update the map checking the conditions:
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr={1,2,3,1,-1,-1,1,4,2,3};
    vector<int> arr2={2,0,0,3,1};
    int K=3;
     
    // int ans1=findLongestSubarray_bf(arr,K);
    // int ans2=findLongestSubarray_bf(arr2,K);   
    
    int ans1=findLongestSubarray(arr,K);
    int ans2=findLongestSubarray(arr2,K); 
    
    cout<<"Length of longest subarray for first array with sum "<<K<<" --> "<<ans1<<endl;
    cout<<"Length of longest subarray for second array with sum "<<K<<" --> "<<ans2<<endl;

    return 0;
}
// Count subarrays with XOR given as K
#include<bits/stdc++.h>
using namespace std;

// Brute
int countSubarr(vector<int> & arr,int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xorr=0;
            for(int k=i;k<=j;k++){
                xorr=xorr ^ arr[k];
            }
            if(xorr==target) cnt++;
        }
    }
    return cnt;
}
// O(n^3),O(1)

// Better --> Reducing no. of loops
int countSubarr_be(vector<int> & arr,int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xorr=0;
        for(int j=i;j<n;j++){
            xorr=xorr ^ arr[j];
            if(xorr==target) cnt++;
        }
    }
    return cnt;
}
// O(n^2),O(1)

// Optimal --> easy peasy 4 lines of code using ***HASHMAP***
int countSubarr_op(vector<int> &arr,int target){
    int n=arr.size();
    map<int,int> mpp;
    int count=0;
    int xorr=0;    // for calculating xor as the array is traversed i.e. XR
    mpp[xorr]++;   // to insert {0,1}
    for(int i=0;i<n;i++){
        xorr = xorr ^ arr[i];    // keep calculating xorr

        int x = xorr ^ target;   // storing prefix / front xor so as to find subarray wirh xor=target

        count=count + mpp[x];    // to update count if x appears in the map

        mpp[xorr]++;             // don't forget to update the map
    }
    return count;
}
// O(nlog n) for map, O(n) / O(n^2) for unordered map
// O(n)

int main(){
    vector<int> arr={4,2,2,6,4,2};
    int K=6;
    // int ans=countSubarr(arr,K);
    // int ans=countSubarr_be(arr,K);
    int ans=countSubarr_op(arr,K);
    cout<<"Number of subarrays with XOR "<<K<<" : "<<ans;
    return 0;
}
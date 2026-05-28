// Minimum days to make M bouquets
// Problem Statement: You are given ‘N’ roses and you are also given an array ‘arr’  where ‘arr[i]’  denotes that the ‘ith’ rose will bloom on the ‘arr[i]th’ day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly ‘k’ adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least ‘m’ bouquets each containing ‘k’ roses. Return -1 if it is not possible.

/*********Solution*********/
// First of all, we can easily figure out the range of answers [min(arr),max(arr)] as we are given up with an array of day numbers.

#include<bits/stdc++.h>
using namespace std;

// To calculate max of array
int maximum(vector<int> arr){
  int n=arr.size();
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

// To calculate max of array
int minimum(vector<int> arr){
  int n=arr.size();
  int min = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

// To count total no. of bouquets formed
int bc(vector<int> arr,int k,int d){    // d is nth day
    int t=0;      // total bouquets that can be formed
    int cnt=0;    // No. of consecutive flowers
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=d){
            cnt++;
        }
        else{
            t+=(cnt/k);
            cnt=0;
        }
    }
    t+=(cnt/k);
    return t;
}

// LS way
int minimum_days(vector<int> arr,int m,int k){
    int n=arr.size();
    int bouquets=0;
    if(m*k>n) return -1;
    for(int i=minimum(arr);i<=maximum(arr);i++){
        bouquets=bc(arr,k,i);
        if(bouquets>=m)
         return i;
    }
    return -1;
}
// O((max(arr)-min(arr)+1)*n)

// BS way
int minimum_days_bs(vector<int> arr,int m,int k){
    int n=arr.size();
    int low=minimum(arr),high=maximum(arr);
    if(m*k>n) return -1;
    while(low<=high){
        int mid=(low+high)/2;
        int bq_formed=bc(arr,k,mid);
        if(bq_formed>=m){
            // May be an answer
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
// O(n*log(max-min+1))

int main(){
    vector<int> bloom_day={7,7,7,7,13,12,11,7};
    int m=2,k=3;
    // int ans=minimum_days(bloom_day,m,k);
    int ans=minimum_days_bs(bloom_day,m,k);
    cout<<"Minimum days to make "<<m<<" bouquets is "<<ans;
    return 0;
}
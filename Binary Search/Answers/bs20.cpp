// Least Capacity to ship packages within D days
// Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within ‘d’ days.
// The weights of the packages are given in an array ‘of weights’. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
// Find out the least-weight capacity so that you can ship all the packages within ‘d’ days.

#include<bits/stdc++.h>
using namespace std;

// We have to analyze if the range of answers can be thought about
// One thing for sure we can say about is that for every item to be shipped, 
// the minimum capacity must be the maximum of the weights and
// the maximum could be the sum of all weights

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

// Sum calculation for weights
int sumc(vector<int> arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

// To calculate time taken in days to ship packages w.r.t capacity
int tt(vector<int> arr,int c)    // c is ship's total capacity(variable)
{
    int n=arr.size();
    int tdt=1;    // first day
    int cap=0;    // filling capacity
    for(int i=0;i<n;i++){
        cap+=arr[i];
        if(cap>c){
            tdt++;
            cap=arr[i];
        }
    }
    return tdt;
}
// Also view the striver's way of solution for this function

// LS way
int lcts(vector<int> arr,int d){
    int n=arr.size();
    for(int i=maximum(arr);i<=sumc(arr);i++){
        int days=tt(arr,i);
        if(days<=d)
         return i;
    }
    return -1;
}
// O(N * (sum(weights[]) – max(weights[]) + 1))

// BS way
int lcts_bs(vector<int> arr,int d){
    int n=arr.size();
    int low=maximum(arr),high=sumc(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int days=tt(arr,mid);
        if(days<=d)
         // may be an answer
         // look for better on left
         high=mid-1;
        else
         // go on right
         low=mid+1;
    }
    return low;
}
// O(N * log2 (sum(weights[]) – max(weights[]) + 1))

int main(){
    // vector<int> weights={1,2,3,4,5,6,7,8,9,10};
    // int D=5;
    // int ans=lcts(weights,D);

    vector<int> weights={1,5,2,9,7,6,14};
    int D=3;
    int ans=lcts_bs(weights,D);
    cout<<"Least capacity of ship so as to ship packages within "<<D<<" days is "<<ans<<" kg";
    return 0;
}
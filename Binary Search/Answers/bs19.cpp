// Find hte smallest divisor given a threshold
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

// Sum calculation for array elements
int sumc(vector<int> arr,int div){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil(double(arr[i])/double(div));
    }
    return sum;
}

// LS way
int smallest_div(vector<int> arr,int t){
    int n=arr.size();
    int total=0;
    for(int i=1;i<=maximum(arr);i++){
        total=sumc(arr,i);
        if(total<=t)
         return i;
    }
    return -1;
}

// BS way
int smallest_div_bs(vector<int> arr,int t){
    int n=arr.size();
    int low=1,high=maximum(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int total_sum=sumc(arr,mid);
        if(total_sum<=t)
         //may be an answer but seek left
         high=mid-1;
        else
         low=mid+1;
    }
    return low;
}

int main(){
    vector<int> nums={1,2,5,9};
    int threshold=6;
    // int ans=smallest_div(nums,threshold);
    int ans=smallest_div_bs(nums,threshold);
    cout<<ans;
    return 0;
}
// Painter's Partition / Split array - largest sum
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

// To calculate total sum of array
int sumc(vector<int> arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

// partition counter & checker
int count_partitions(vector<int> arr,int u){
    int n=arr.size();
    int partitions=1;   // partition count
    int units=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]+units<=u){
            units+=arr[i];
        }
        else{
            partitions++;
            units=arr[i];
        }
    }
    return partitions;
}

// ls
int painters_partition(vector<int> arr,int k){
    for(int units=maximum(arr);units<=sumc(arr);units++){
        int p=count_partitions(arr,units);
        if(p==k) return units;
    }
}

// bs
int sa_ls(vector<int> arr,int k){
    int low=maximum(arr),high=sumc(arr);     // sub-array sum parameters
    while(low<=high){
        int mid=(low+high)/2;
        int sub_arrays=count_partitions(arr,mid);   // same function called count_subarrays
        if(sub_arrays>k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}

int main(){
    vector<int> arr={10,20,30,40};
    int k=2;
    // int ans=painters_partition(arr,k);
    int ans=sa_ls(arr,k);
    cout<<"Min(max) : "<<ans;
    return 0;
}
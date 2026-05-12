// Maximum product subarray in an array
#include<bits/stdc++.h>
using namespace std;

// Brute
int maxSubProduct_bf(vector<int> &arr){
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int pro=1;
            for(int k=i;k<=j;k++){
                pro*=arr[k];
                maxi=max(maxi,pro);
            }
        }
    }
    return maxi;
}

// Optimized Brute --> Better
int maxSubProduct_be(vector<int> &arr){
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int pro=1;
        for(int j=i;j<n;j++){
            pro*=arr[j];
            maxi=max(maxi,pro);    
        }
    }
    return maxi;
}

// Optimal
int maxSubProduct_op(vector<int> &arr){
    int n=arr.size();
    int maxi=INT_MIN;
    int prefix=1,suffix=1;
    for(int i=0;i<n;i++){
        prefix*=arr[i];
        suffix*=arr[n-1-i];
        if(prefix==0) prefix=1;
        if(suffix==0) suffix=1;
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
}

int main(){
    vector<int> arr={3,2,-1,4,-6,3,-2,6};
    //int ans=maxSubProduct_bf(arr);
    //int ans=maxSubProduct_be(arr);
    int ans=maxSubProduct_op(arr);
    
    cout<<"Maximum subarray product : "<<ans;
    return 0;
}
// Count subsequences with sum as K
#include<bits/stdc++.h>
using namespace std;

int countS(int ind,int n,int arr[],int k,int &sum){
    
    // Base case
    if(ind==n){
        if(sum==k) return 1;
        else return 0;
    }

    sum+=arr[ind];
    int l=countS(ind+1,n,arr,k,sum);

    sum-=arr[ind];
    int r=countS(ind+1,n,arr,k,sum);

    return l+r;
}

int main(){
    int arr[]={3,1,2};
    int n=sizeof(arr)/ sizeof(arr[0]);
    int k=3;
    int sum=0;
    int ans=countS(0,n,arr,k,sum);
    cout<<ans;
    return 0;
}
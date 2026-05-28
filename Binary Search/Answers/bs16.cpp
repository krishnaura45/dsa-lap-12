// Find the nth root of a number m
// n=3,m=27 --> 3
// n=4,m=69 --> -1
// need to deal with OVERFLOW case also that ntp can generate with input like m=10^9 and n=10

#include<bits/stdc++.h>
using namespace std;

// Required function --> N times product
int ntp(int num,int n){
    int p=1;  // product calculation (i*i*..)
    for(int j=1;j<=n;j++){
        p=p*num;
    }
    return p;
}
// O(n) ==> O(log2 n) by power exponential method

// Optimized ntp
int ntp_op(int num,int n,int m){
    int p=1;  // product calculation (i*i*..)
    for(int j=1;j<=n;j++){
        p=p*num;
        if(p>m) return 2;
    }
    if(p==m) return 1;
    return 0;
}

// Linear search 
int nth_root(int m,int n){
    for(int i=1;i<=m;i++){
        if(ntp(i,n)==m) return i;
        else if(ntp(i,n)>m) break;
    }
    return -1;
}
// O(m*n) ==> O(m*log2 n)

// Binary Search
int nth_root_op(int m,int n){
    int low=1,high=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(ntp_op(mid,n,m)==1)
         return mid;
        
        else if(ntp_op(mid,n,m)<1)
         // go on right
         low=mid+1;

        else
         // go on left
         high=mid-1;
    }
    return -1;
}
// (n*log2 m) ==> (log2 n) * log2 m

int main(){
    int m=64;  // 27,64,69
    int n=3;
    // int ans=nth_root(m,n);
    int ans=nth_root_op(m,n);
    cout<<n<<"th root of "<<m<<" is "<<ans;
    return 0;
}
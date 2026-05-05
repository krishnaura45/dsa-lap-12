#include<bits/stdc++.h>
using namespace std;

// Number hashing
int main(){
    int n;   // size of integer array
    cin>>n;
    int arr[n];   // integer array
    for(int i=0;i<n;i++) cin>>arr[i];

    // precompute
    int atmax;   // max value that can be stored
    cin>>atmax;
    int hash[atmax+1]={0};
    for(int i=0;i<n;i++) hash[arr[i]]+=1;

    // fetch
    int q;   // no. of queries
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<"Frequency of "<<num<<" --> "<<hash[num]<<endl;
    }

    return 0;
}
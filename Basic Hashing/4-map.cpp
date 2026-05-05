#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // Precompute
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    // Iterate in the map
    for(auto it:mpp) cout<<it.first<<"-->"<<it.second<<endl;

    int q;
    cin>>q;
    while(q>0){
        int num;
        cin>>num;
        // fetch
        cout<<mpp[num]<<endl;   // returning the freq. of num
        q--;
    }
    return 0;
}
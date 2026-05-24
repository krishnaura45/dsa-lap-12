// Print any subsequence whose sum is K
#include<bits/stdc++.h>
using namespace std;

bool printS(int ind,int n,int arr[],int k,int &s,vector<int> &ls){
    // Base case
    if(ind==n){
        // condition satisfied
        if(s==k){
            for(auto it:ls) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        // condition not satisfied
        else return false;
    }

    ls.push_back(arr[ind]);
    // pick/take
    s+=arr[ind];
    if(printS(ind+1,n,arr,k,s,ls)==true){
        return true;
    }

    ls.pop_back();
    // not take
    s-=arr[ind];
    if(printS(ind+1,n,arr,k,s,ls)==true){
        return true;
    }

    // If none of them returns true
    return false;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    int k=3;
    int sum=0;
    vector<int> ls={};
    bool ans=printS(0,n,arr,k,sum,ls);
    if(ans) cout<<"Single printing done";
    return 0;
}
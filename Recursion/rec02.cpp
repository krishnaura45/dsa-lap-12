// Print all subsequences whose sum is K
#include<bits/stdc++.h>
using namespace std;

void print_subs(int ind,int n,int arr[],int k,vector<int> &ls){
    
    // Base case
    if(ind==n){ 
        int sum=0;
        for(auto it:ls) sum+=it;
        if(sum==k){
            for(auto it:ls) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ls.push_back(arr[ind]);
    // take
    print_subs(ind+1,n,arr,k,ls);
    // not take
    ls.pop_back();
    print_subs(ind+1,n,arr,k,ls);

}
// O(2^n * 2n) => O(2^n+1 * n) , O(n)

void printS(int ind,int n,int arr[],int k,int &sum,vector<int> &ls){
    // Base case
    if(ind==n){
        if(sum==k){
            for(auto it:ls) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    // take
    ls.push_back(arr[ind]);
    sum+=arr[ind];
    printS(ind+1,n,arr,k,sum,ls);
    // not take
    ls.pop_back();
    sum-=arr[ind];
    printS(ind+1,n,arr,k,sum,ls);
}
// O(n*2^n), O(n)

int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin>> arr[i];
    // int k=3;
    // vector<int> ls={};
    // print_subs(0,n,arr,k,ls);

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    int k=3;
    int sum=0;
    vector<int> ls={};
    printS(0,n,arr,k,sum,ls);
    return 0;
}
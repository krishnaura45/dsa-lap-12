// Print all subsequences
#include<bits/stdc++.h>
using namespace std;

void print_subs(int ind,int n,int arr[],vector<int> &ls){
    
    // Base case
    if(ind==n){
        for(auto it:ls) cout<<it<<" ";
        if(ls.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    ls.push_back(arr[ind]);
    // take
    print_subs(ind+1,n,arr,ls);
    // not take
    ls.pop_back();
    print_subs(ind+1,n,arr,ls);

}
// O(2^n * n),O(n)

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>> arr[i];
    vector<int> ls={};
    print_subs(0,n,arr,ls);
    return 0;
}
// Subset sums - I
#include<bits/stdc++.h>
using namespace std;
 
void subsets(int ind,vector<int> arr,int &sum,vector<int> &ds){
    int n=arr.size();
    
    // Base case 
    if(ind==n){
        ds.push_back(sum);
        return;
    }

    // pick
    sum+=arr[ind];
    subsets(ind+1,arr,sum,ds);

    // not pick
    sum-=arr[ind];
    subsets(ind+1,arr,sum,ds);
}

vector<int> subset_sums1(vector<int> arr){
    vector<int> list;
    int sum=0;
    subsets(0,arr,sum,list);
    sort(list.begin(),list.end());
    return list;
}
// O(m + mlogm) , O(m) where m=2^n

int main(){
    vector<int> arr={3,1,2};
    vector<int> ans=subset_sums1(arr);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}
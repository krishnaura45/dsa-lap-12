// Union of two sorted arrays
#include<bits/stdc++.h>
using namespace std;

// Brute force approach --> as union contains unique elements therefore we can use SET data structure
void union_bf(vector<int> &arr1,vector<int> &arr2){
    set<int> st;
    int m=arr1.size();
    int n=arr2.size();
    for(int i=0;i<m;i++) st.emplace(arr1[i]);
    for(int i=0;i<n;i++) st.emplace(arr2[i]);
    
    // UNION
    vector<int> u;
    for(auto it:st){
        u.push_back(it);
    }
    
    for(auto it:u) cout<<it<<" ";
}
// Time complexity --> O(mlogN + nlogN) + O(m+n) = O((m+n)log(m+n)) where N is no of elements in set
// Space complexity --> O(m+n) + O(m+n)= O(m+n) for set and union

// Optimal Solution --> using two pointer approach
void union_op(vector<int> &a,vector<int> &b){
    int m=a.size();
    int n=b.size();
    vector<int> Union;
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<=b[j]){
            if(Union.size()==0 || Union.back() != a[i]) Union.push_back(a[i]);
            i++;
        }
        else{
            if(Union.size()==0 || Union.back() != b[j]) Union.push_back(b[j]);
            j++;
        }
    }
    while(i<m){
        if(Union.size()==0 || Union.back() != a[i])
         Union.push_back(a[i]);
        i++;
    }
    while(j<n){
        if(Union.size()==0 || Union.back() != b[j])
         Union.push_back(b[j]);
        j++;
    }

    for(auto it:Union) cout<<it<<" ";
}
// Time complexity --> O(m+n) Because at max i runs for m times and j runs for n times when there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct
// Space complexity --> O(m+n) considering union array list

int main(){
    vector<int> a1={1,1,3,5};
    vector<int> a2={2,4,4,6};
    // union_bf(a1,a2);
    union_op(a1,a2);
    return 0;
}
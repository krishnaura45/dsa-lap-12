// Subset - II
// Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.
#include<bits/stdc++.h>
using namespace std;

// Brute force
void find_subsets(int ind,vector < int > & arr, set<vector<int>> &st, vector < int > & ds) {
    if (ind == arr.size()) {
        st.insert(ds);
        return;
    }
    
    // if the element is picked up
    ds.push_back(arr[ind]);
    find_subsets(ind+1,arr,st,ds);

    // if element is not pickeed up
    ds.pop_back();
    find_subsets(ind+1,arr,st,ds);
}

set<vector<int>> subset2(vector<int> arr){
    set < vector < int >> ans;
    vector < int > ds;
    find_subsets(0,arr,ans,ds);
    return ans;
}
// O(2^n * klog x) where k is the average length of each subset and x is the no. of unique subsets / set size
// O(2^n*k)

// optimal
void find_subsets_op(int ind,vector < int > & arr, vector<vector<int>> &lol, vector < int > & ds) {
    if(ind>arr.size()) return;
    lol.push_back(ds);
    for(int i=ind;i<arr.size();i++){
        if(i>ind && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        find_subsets_op(i+1,arr,lol,ds);
        ds.pop_back();
    }
}

vector<vector<int>> subset2_op(vector<int> arr){
    vector < vector < int >> ans;
    vector < int > ds;
    find_subsets_op(0,arr,ans,ds);
    return ans;
}
// Time Complexity: O(k * 2^n)
// Space Complexity: O(2^n * k) to store every subset of average length k

int main() {
  vector < int > v {1,2,2};
//   set < vector < int >> ans = subset2(v);
//   for(auto it:ans){
//     cout<<"[";
//     for(auto ele:it){
//         cout<<ele<<" ";
//     }
//     cout<<"]";
//     cout<<endl;
//   }
  
  vector < vector < int >> ans = subset2_op(v);
  for(auto it:ans){
    cout<<"[";
    for(auto ele:it){
        cout<<ele<<" ";
    }
    cout<<"]";
    cout<<endl;
  }
  return 0;
}
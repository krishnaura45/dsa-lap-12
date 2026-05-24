// Combination sum - II
// Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.
#include<bits/stdc++.h>
using namespace std;

// brute
void find_combination(int ind, int target, vector < int > & arr, set < vector < int >> & ans, vector < int > & ds) {
    if (ind == arr.size()) {
        if (target == 0) {
          ans.insert(ds);
        }
        return;
    }
    
    // if the element is picked up
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        find_combination(ind+1, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    // if element is not pickeed up
    find_combination(ind + 1, target, arr, ans, ds);
}

set<vector<int>> combination_sum2(vector<int> &candidates,int target){
    sort(candidates.begin(), candidates.end());
    set < vector < int >> ans;
    vector < int > ds;
    find_combination(0, target, candidates, ans, ds);
    return ans;
}
// O(2^n * klogn) where k is the average length of set, ignore sorting time
// O(k*x), x is the no. of combinations

// optimal
void find_combination_op(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  // base case
  if (target == 0) {
    ans.push_back(ds);
    return;
  }

  // loop
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    find_combination_op(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combination_sum2_op(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  find_combination_op(0, target, candidates, ans, ds);
  return ans;
}
// O(2^n * k) where k is the average length of set, ignore sorting time
// O(k*x), x is the no. of combinations

int main() {
  vector<int> v ={10,1,2,7,6,1,5};
  int target = 8;

//   set < vector < int >> ans = combination_sum2(v, target);
//   cout << "Combinations are: " << endl;
//   for (auto it:ans) {
//     for (auto ele:it)
//       cout << ele << " ";
//     cout << endl;
//   }

  vector < vector < int >> comb = combination_sum2_op(v, 8);
  for (int i = 0; i < comb.size(); i++) {
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << endl;
  }
}
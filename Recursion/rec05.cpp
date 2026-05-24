// Combination sum - I
// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
#include<bits/stdc++.h>
using namespace std;

void find_combination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
    if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
    }
    
    // if the element is picked up
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        find_combination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
    }

    // if element is not pickeed up
    find_combination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combination_sum1(vector<int> &candidates,int target){
    vector < vector < int >> ans;
    vector < int > ds;
    find_combination(0, target, candidates, ans, ds);
    return ans;
}
// O(2^t * k) where t is the target, k is the average length
// O(k*x), k is the average length and x is the no. of combinations

int main() {
  vector < int > v {3,4,6,7};
  int target = 7;

  vector < vector < int >> ans = combination_sum1(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}
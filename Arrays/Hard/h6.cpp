// Merge overlapping sub-intervals
#include<bits/stdc++.h>
using namespace std;

// Brute
vector<vector<int>> mergeOverlaps(vector<vector<int>> &arr){
    vector<vector<int>> ans;
    int n=arr.size();
    //sort the given intervals:
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) { // select an interval:
        int start = arr[i][0];
        int end = arr[i][1];

        //Skip all the merged intervals:
        if (!ans.empty() && end <= ans.back()[1]) {
            continue;
        }

        //check the rest of the intervals:
        for (int j = i + 1; j < n; j++) {
            if (arr[j][0] <= end) {
                end = max(end, arr[j][1]);
            }
            else {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
// O(n log n) + O(2n) , O(n)

// Optimal --> one pass iteration
vector<vector<int>> mergeOverlaps_op(vector<vector<int>> &arr){
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++){
        // if the current interval does not lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr={{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    // vector<vector<int>> ans=mergeOverlaps(arr);
    vector<vector<int>> ans=mergeOverlaps_op(arr);
    for(auto it:ans){
        cout<<"(";
        for(auto ele:it) cout<<ele<<" ";
        cout<<")"<<endl;
    }
}
// Two sum problem --> 2nd variant
#include<bits/stdc++.h>
using namespace std;

vector<int> twosum_obf(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> index;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            if(sum==k){
                index.push_back(i);
                index.push_back(j);
                return index;
            }
        }
    }
    return {-1,-1};
}
// O(N^2),O(1)

// Optimal approach for variant 2 -->>> marked
vector<int> twosum_be(vector<int> &arr, int target) {
    int n=arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}
// T.C --> O(N) in best case and O(N^2) in worst case,
// S.C-->O(N)

int main(){
    vector<int> arr={1,2,6,5,8,7};
    int target=14;
    vector<int> ans=twosum_obf(arr,target);
    cout<<"["<<ans[0]<<","<<ans[1]<<"]"<<endl;
    return 0;
}
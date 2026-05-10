// Two sum problem --> 1st variant
#include<bits/stdc++.h>
using namespace std;
// BRUTE
string twosum_bf(vector<int> &arr,int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0 ;j<n;j++){
            if(i==j) continue;
            int sum=arr[i]+arr[j];
            if(sum==k) return "YES";
        }
    }
    return "NO";
}
// O(N^2),O(1)

// BETTER -->>> marked
string twosum_be(vector<int> &a,int k){
    int n=a.size();
    map<int,int> mpp;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        int moreNeeded = k - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
// O(NlogN),O(N)

// OPTIMAL approach for variant 1 --> using two pointer 
// but it involves distortion of array
string twosum(vector<int> &arr, int target) {
    int n=arr.size();
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
// T.C --> O(N) + O(NlogN) = O(NlogN),
// S.C --> O(1) / O(N) if distortion of array is considered

int main(){
    vector<int> arr={1,2,6,5,8,7};
    int target=14;
    string ans=twosum(arr,target);
    cout<<ans<<endl;
    return 0;
}
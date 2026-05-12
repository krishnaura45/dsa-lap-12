// Majority element in an array (> n/3 times)
// There can be max of 2 elements in majority for >n/3 times
#include<bits/stdc++.h>
using namespace std;

// BRUTE --> using an extra set
vector<int> majorityElement(vector<int> &a)
{
    int n=a.size();
    vector<int> ans;
    set<int> st;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==a[i]) cnt++;
        }
        if(cnt>n/3) st.insert(a[i]);
    }
    for(auto it:st) ans.push_back(it);
    if(ans.size()>0) return ans;
    return {-1};
}
// O(n^2*2log2),O(1)

// Optimized Brute
vector<int> majorityElement_obf(vector<int> v) {
    int n = v.size(); //size of the array
    vector<int> ans; // list of answers

    for (int i = 0; i < n; i++) {
        //selected element is v[i]:
        // Checking if v[i] is not already a part of the answer:
        if (ans.size() == 0 || ans[0] != v[i]) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                // counting the frequency of v[i]
                if (v[j] == v[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ans.push_back(v[i]);
        }

        if (ans.size() == 2) break;
    }
    return ans;
}
// O(n^2),O(1)

// BETTER --> using hashmap
vector<int> majorityElement_be(vector<int> &a){
    vector<int> ans;
    int n=a.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    for(auto it:mpp){
        if(it.second>n/3) ans.push_back(it.first);
    }

    if(ans.size()>0) return ans;
    else return {-1};
}
// T.C --> O(nlogn) + O(n) => O(nlogn), 
// S.C --> O(n)

// OPTIMAL --> using Moore's Voting Algorithm
vector<int> majorityElement_op(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;

    int cnt1=0,cnt2=0;
    int el1,el2;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=el2){
            el1=arr[i];
            cnt1=1;
        }

        else if(cnt2==0 && arr[i]!=el1){
            el2=arr[i];
            cnt2=1;
        }

        else if(arr[i]==el1) cnt1++;
        else if(arr[i]==el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    // verifying for major elements
    int count=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==el1) count++;
        if(arr[i]==el2) count2++;
    }
    
    if(count>n/3) ans.push_back(el1);
    if(count2>n/3) ans.push_back(el2);
    
    if(ans.size()>0) return ans;
    else return {-1};
}
// O(n) + O(n), O(1)

int main(){
    vector<int> arr={1,1,1,3,3,3,2,2};
    // vector<int> ans=majorityElement(arr);
    // vector<int> ans=majorityElement_obf(arr);
    // vector<int> ans=majorityElement_be(arr);
    vector<int> ans=majorityElement_op(arr);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}
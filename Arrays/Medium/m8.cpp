// Leaders in an array
#include<bits/stdc++.h>
using namespace std;

// Brute
vector<int> leaders(vector<int> &arr){
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        bool leader=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.push_back(arr[i]);
        }
    }
    //sort(ans.begin(),ans.end());
    return ans;
}
// O(n^2),O(n)

// Optimal
vector<int> leaders_op(vector<int> & arr){
    int n=arr.size();
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi=max(arr[i],maxi);
    }

    // To keep the leaders in the order they were
    reverse(ans.begin(),ans.end());
    return ans;
}
// O(2n),O(n)

int main(){
    vector<int> ar={10,2,22,12,3,0,6};
    vector<int> ans=leaders(ar);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
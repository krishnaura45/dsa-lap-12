// 3 sum problem --> find all unique triplets such that target sum is 0
#include<bits/stdc++.h>
using namespace std;

// Brute --> gives triplets but not unique
vector<vector<int>> threeSum_b1(vector<int> &arr){
    vector<vector<int>> ans;
    int n=arr.size();
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                temp.clear();
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==0){
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                }
                if(temp.size()!=0)
                 ans.push_back(temp);
            }
        }
    }
    return ans;
}
// O(n^3),O(no of triplets)

// Brute --> gives unique triplets
vector<vector<int>> threeSum_b2(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==0){
                    vector<int> temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// O(n^3 * log(no. of triplets)), 2*O(no of triplets)

// Better
vector<vector<int>> threeSum_be(vector<int> &arr){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int el3=-(arr[i]+arr[j]);
            if(hashset.find(el3) != hashset.end()){
                vector<int> temp={arr[i],arr[j],el3};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// O(n^2 * log m) , O(n)+ 2*O(no. of unique triplets)

// Optimal --> 2 pointer
vector<vector<int>> threeSum_op(vector<int>& arr) {
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k+1]) k--;
            }
        }
    }
    return ans;
}
// O(nlogn) + O(n^2) , O(no.of unique triplets)

int main(){
    vector<int> arr={-1,0,1,2,-1,3,-4};
    // vector<vector<int>> ans=threeSum_b1(arr);
    // vector<vector<int>> ans=threeSum_b2(arr);
    // vector<vector<int>> ans=threeSum_be(arr);
    vector<vector<int>> ans=threeSum_op(arr);
    for(auto it:ans){
        cout<<"[";
        for(auto ele:it) cout<<ele<<" ";
        cout<<"]"<<endl;
    }
}
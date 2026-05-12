// 4 sum problem
#include<bits/stdc++.h>
using namespace std;

// Brute 
vector<vector<int>> fourSum_bf(vector<int> &arr,int target){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum=arr[i]+arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum==target){
                        vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// O(n^4 *log(no of quads)) , 2*O(no. of unique quads)

// Better --> using hashmap or hashset
vector<vector<int>> fourSum_be(vector<int> &arr,int target){
    int n=arr.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int fourth=target-(arr[i]+arr[j]+arr[k]);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// O(n^3 * log m) , O(n)+2*O(no. of unique quads)

// Optimal --> 2 pointer
vector<vector<int>> fourSum_op(vector<int> &arr,int target){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>i+1 && arr[j]==arr[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                int sum = arr[i]+arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum<target) k++;
                else if(sum>target) l--;
                else{
                    vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && arr[k]==arr[k-1]) k++;
                    while(k<l && arr[l]==arr[l+1]) l--;
                }
            }
        }
    }
    return ans;
}
// O(nlog n) + O(n^3) , O(no. of unique quads) to return answer

int main(){
    // int target=0;
    // vector<int> arr={1,0,-1,0,-2,2};
    // vector<vector<int>> ans=fourSum_bf(arr,target);

    // vector<int> arr={1,2,-1,-2,2,0,-1};
    // vector<vector<int>> ans=fourSum_be(arr,target);

    int target = 8;
    vector<int> arr={1,1,1,2,2,2,3,3,3,4,4,4,5,5};
    vector<vector<int>> ans=fourSum_op(arr,target);
    for(auto it:ans){
        for(auto ele:it) cout<<ele<<" ";
        cout<<endl;
    }
}
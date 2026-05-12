// Print all Inversions possible
#include<bits/stdc++.h>
using namespace std;

// Brute
vector<vector<int>> countInversions(vector<int> &arr){

    int n=arr.size();
    vector<vector<int>> v;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                vector<int> temp={arr[i],arr[j]};
                v.push_back(temp);
            }
        }
    }
    return v;
}

int main(){
    vector<int> arr={5,3,2,4,1};
    vector<vector<int>> ans=countInversions(arr);
    for(auto it:ans){
        for(auto ele:it) cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}
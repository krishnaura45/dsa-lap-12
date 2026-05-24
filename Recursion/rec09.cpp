// Print all permutations of a string or array --> Approach 1
#include<bits/stdc++.h>
using namespace std;

// to generate permutations
void generateP(vector<int> arr,vector<int> ds,map<int,int> &mpp,vector<vector<int>> &pl){
    int n=arr.size();
    // base case
    if(ds.size()==n){
        pl.push_back(ds);
        return;
    }

    for(int i=0;i<n;i++){
        if(!mpp[i]){
            // add current to data structure
            ds.push_back(arr[i]);
            // mark it in map
            mpp[i]=1;
            // move to next level
            generateP(arr,ds,mpp,pl);

            // unmark map and remove last element
            mpp[i]=0;
            ds.pop_back();
        }
    }
}

// to get permutations
vector<vector<int>> getP(vector<int> arr){
    vector<vector<int>> pl;
    vector<int> ds;
    map<int,int> mpp;
    generateP(arr,ds,mpp,pl);
    return pl;
}
// O(n!*n), O(n)+O(n)
// ignoring auxilliary space -> O(n) for the depth of recursion

// to print permutations
void printP(vector<vector<int>> p){
    for(auto it:p){
        for(auto ele:it) cout<<ele<<" ";
        cout<<endl;
    }
}

int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans=getP(arr);
    printP(ans);
    return 0;
}
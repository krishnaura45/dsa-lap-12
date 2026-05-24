// Print all permutations of a string or array --> Approach 2
#include<bits/stdc++.h>
using namespace std;

// to generate permutations
void generateP(int ind,vector<int> arr,vector<vector<int>> &pl){
    int n=arr.size();
    // base case
    if(ind==n){
        pl.push_back(arr);
        return;
    }

    for(int i=ind;i<n;i++){
        // swap --> similar to adding
        swap(arr[ind],arr[i]);
        generateP(ind+1,arr,pl);

        // after coming back from recursion, reswap --> similar to removing
        swap(arr[ind],arr[i]);
    }
}

// to get permutations
vector<vector<int>> getP(vector<int> arr){
    vector<vector<int>> pl;
    generateP(0,arr,pl);
    return pl;
}
// O(n!*n), O(1)
// ignoring auxilliary space -> O(n) for the depth of recursion and O(n!) for printing

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
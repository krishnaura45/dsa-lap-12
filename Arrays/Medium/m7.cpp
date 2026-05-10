// Next permutation of an array
#include<bits/stdc++.h>
using namespace std;

// Brute --> Generate all permutations, apply linear search for the given permutation and print the just next permutation
// T.C --> O(n*n!) + O(n)

// Better --> Using c++ stl
vector<int> nextGreaterPermutation(vector<int> &arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

// Optimal approach --> Observation =>
// 1. Figure out the breakpoint/dip by making the longest prefix match
// 2. Find someone slightly >1, but the smallest one so that you stay close
// 3. To keep the no as small as possible, sort the rest in ascending order
vector<int> nextGreaterPermutation_op(vector<int> &arr){
    int n=arr.size();
    
    // Finding out dip index
    int dip=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            dip=i;
            break;
        }
    }
    if(dip==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }

    // step 2
    for(int i=n-1;i>dip;i--){
        if(arr[i]>arr[dip]){
            swap(arr[i],arr[dip]);
            break;
        }
    }

    // step 3
    reverse(arr.begin()+dip+1,arr.end());
    return arr;
}
// O(3n),O(1)

int main(){
    vector<int> arr={2,1,5,4,3,0,0};
    //vector<int> ans=nextGreaterPermutation(arr);
    vector<int> ans=nextGreaterPermutation_op(arr);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
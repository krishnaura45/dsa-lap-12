// Search in a sorted 2D matrix --> SI2D-I
// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.

#include<bits/stdc++.h>
using namespace std;

bool search_2d(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    bool ans=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                ans=true;
                break;
            }
        }
    }
    return ans;
}
// O(nm)

bool search_2d_bs(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    bool ans=false;
    for(int i=0;i<n;i++){
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[i][mid]==target){
                ans=true;
                break;    
            }
            else if(arr[i][mid]<target)
             low=mid+1;
            else 
             high=mid-1;
        }
    }
    return ans;
}
// O(nlog m)

int main(){
    vector<vector<int>> arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    // bool ans=search_2d(arr);
    bool ans=search_2d_bs(arr,6);
    cout<<ans;
    return 0;
}
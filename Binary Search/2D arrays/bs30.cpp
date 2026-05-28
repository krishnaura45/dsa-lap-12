// Search in a row and column-wise sorted matrix --> SI2D-II
#include<bits/stdc++.h>
using namespace std;

vector<int> search_2d2(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==target){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
// O(nm)

vector<int> search_2d2_bs(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[i][mid]==target){
                return {i,mid};    
            }
            else if(arr[i][mid]<target)
             low=mid+1;
            else 
             high=mid-1;
        }
    }
    return {-1,-1};  
}
// O(nlog m)

// Optimized Binary Search
vector<int> search_2d2_obs(vector<vector<int>> arr,int target){
    int n=arr.size();
    int m=arr[0].size();
    int row=0,col=m-1;
    while(row<n && col>=0){
        int mid=arr[row][col];
        if(mid==target){
            return {row,col};
        }
        else if(target<mid)
         col--;
        else
         row++;
    }
    return {-1,-1};  
}
// O(n+m)

int main(){
    vector<vector<int>> arr={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24}};
    // vector<int> ans=search_2d2(arr,14);
    // vector<int> ans=search_2d2_bs(arr,6);
    vector<int> ans=search_2d2_obs(arr,14);
    cout<<ans[0]<<","<<ans[1];
    return 0;
}
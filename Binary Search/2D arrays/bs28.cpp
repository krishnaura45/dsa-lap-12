// ***BS on 2D arrays***
// Find the row with maximum number of ones
#include<bits/stdc++.h>
using namespace std;

int max_ones_2d(vector<vector<int>> arr){
    int n=arr.size();
    int m=arr[0].size();
    int max_cnt=-1;
    int req_row=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=0;
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                cnt_ones=m-j;
                break;
            }
        }
        if(max_cnt<cnt_ones){
            max_cnt=cnt_ones;
            req_row=i;
        }
    }
    return req_row;
}
// O(nm)

int max_ones_2d_bs(vector<vector<int>> arr){
    int n=arr.size();
    int m=arr[0].size();
    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int lb=lower_bound(arr[i].begin(),arr[i].end(),1)-arr[i].begin();
        int cnt_ones = m - lb;
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}
// O(nlog m)

int main(){
    vector<vector<int>> arr={{0,0,0,0,1},{0,0,0,1,1},{0,0,1,1,1},{0,1,1,1,1},{0,0,1,1,1}};
    // int ans=max_ones_2d(arr);
    int ans=max_ones_2d_bs(arr);
    cout<<"The row with maximum no. of 1's is: "<<ans;
    return 0;
}
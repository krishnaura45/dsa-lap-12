// Rotate array by 90 degrees / Rotate image (nxn matrix)
#include<bits/stdc++.h>
using namespace std;

// Brute --> using an additional array of same size
vector<vector<int>> rotateArray(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Declare a 2d list array
    vector<vector<int>> rotated(n, vector<int> (n,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}
// O(n^2),O(n^2)

void transpose(vector<vector<int>> &arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

// Optimal --> In place rotation
vector<vector<int>> rotateArray_op(vector<vector<int>> &arr,int n){
    // transpose each row or column 
    // transpose(arr,n); 
    for (int i = 0; i < n-1; ++i)
      for (int j = i + 1; j < n; ++j)
        swap(matrix[i][j], matrix[j][i]);
    
    // reverse each row
    for (int i = 0; i < n; ++i)
        reverse(matrix[i].begin(), matrix[i].end());
}
// O(2*n^2),O(1)

int main(){
    vector<vector<int>> arr={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n = arr.size();
    cout<<"Original Matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    //vector<vector<int>> ans=rotateArray(arr);
    vector<vector<int>> ans=rotateArray_op(arr,n);
    cout<<"Matrix after 90 degree rotation :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;

}
// Set Matrix Zeroes
#include<bits/stdc++.h>
using namespace std;

void row_marker(vector<vector<int>> &arr,int i){
    int m=arr[0].size();
    for(int j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
// O(m)
void column_marker(vector<vector<int>> &arr,int j){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1;
        }
    }
}
// O(n)

// Brute
void setMatrixZeros(vector<vector<int>> &arr){
    int n = arr.size();     // rows
    int m = arr[0].size();  // columns
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row_marker(arr,i);
                column_marker(arr,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
}
// T.C --> O(nm*(n+m)) + O(nm) = O(nm(1+n+m)) => somewhat O(n^3) , 
// S.C --> O(1)

// Better
void setMatrixZeros_be(vector<vector<int>> &arr){
    int n = arr.size();     // rows
    int m = arr[0].size();  // columns

    int row[n]={0};  // row tracker array
    int col[m]={0};  // column tracker array
    // First traversal --> tracking row / column for the final matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    // Second traversal --> actual setting
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                arr[i][j]=0;
            }
        }
    }
}
// O(2nm) => somewhat O(n^2) , O(n+m) 

// Optimal --->>> marked
void setMatrixZeros_op(vector<vector<int>> &matrix){
    int n = matrix.size();     // rows
    int m = matrix[0].size();  // columns

    // int row[n] --> arr[..][0]   // row tracker
    // int col[m] --> arr[0][..]   // column tracker
    // First traversal --> tracking row / column for the final matrix
    int col0=1;

    // Step 1: Traverse the matrix and mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Step 3: Finally mark the col array & then row array:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }
}
// O(2nm) => O(n^2) , O(1)

int main(){
    vector<vector<int>> matrix={{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    cout<<"Matrix before setting zeroes :"<<endl;
    for(auto it:matrix){
        for(auto ele:it) cout<<ele<<" ";
        cout<<endl;
    }

    //setMatrixZeros(matrix);
    //setMatrixZeros_be(matrix);
    setMatrixZeros_op(matrix);
    cout<<"Matrix after setting zeroes :"<<endl;
    for(auto it:matrix){
        for(auto ele:it) cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}
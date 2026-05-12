// Pascal Triangle
#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){          // optimal approach for finding nCr
    int res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

// Variation 1
int pascal_element(int r,int c){          // r -> row no, c -> column no 
    int v = nCr(r-1,c-1);
    return v;
}
// O(r)

// Variation 2
// Extreme Brute
void generate_row(int n){      /// n is row number
    for(int c=1;c<=n;c++){
        int row_value= nCr(n-1,c-1);
        cout<<row_value<<" ";
    }
}
// O(n*r)

// Optimal
vector<int> generate_PascalRow(int n){
    vector<int> row;
    long long ans = 1;
    row.push_back(ans); // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        row.push_back(ans);
    }
    return row;
}
// O(n), O(1)

// Variation 3
// Naive approach
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}
// O(n*n*r) ~ O(n3), O(1)

// Optimal
vector<vector<int>> pascalTriangle_op(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generate_PascalRow(row));   // using row generation from v2
    }
    return ans;
}
// O(n^2), O(1)

int main(){
    int r=5,c=2;
    int n=6;
    // int ans=pascal_element(r,c);
    // cout<<"Element at position("<<r<<','<<c<<") : "<<ans;

    // pascalTriangle_v2(n);
    // vector<int> ans=generate_PascalRow(n);

    // vector<vector<int>> ans = pascalTriangle(n);
    vector<vector<int>> ans = pascalTriangle_op(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
// Intersection of two sorted arrays
#include<bits/stdc++.h>
using namespace std;

vector<int> intersection_bf(vector<int> &a,vector<int> &b){
    int m=a.size();
    int n=b.size();
    vector<int> common;
    int vis[n]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j && vis[j]==0]){
                common.push_back(a[i]);
                vis[j]=1;
                break;
            }
            if(b[j]>a[i]) break;
        }
    }

    return common;
}
// O(mn),O(n)

vector<int> intersection_op(vector<int> &a,vector<int> &b){
    int m=a.size();
    int n=b.size();
    vector<int> common;
    int i=0,j=0;
    while(i<m && j<n){
        if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i])
        {
            j++;
        }
        else{
            common.push_back(a[i]);
            i++;
            j++;
        }
    }

    return common;
}
// O(m+n),O(1)

int main(){
    vector<int> a1={1,1,2,3,4,5};
    vector<int> a2={2,3,4,4,5,6};
    vector<int> i=intersection_op(a1,a2);

    for(auto & it:i) cout<<it<<" ";
    return 0;
}
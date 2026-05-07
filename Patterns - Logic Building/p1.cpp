#include<bits/stdc++.h>
using namespace std;

// Simple Half Triangle
int main(){
    int n;
    cout<<"Enter pattern size"<< endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
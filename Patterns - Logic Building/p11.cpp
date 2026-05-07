#include<bits/stdc++.h>
using namespace std;

// Binary Triangle
void pattern_izer(int n){
    int bin=1;
    for(int i=1;i<=n;i++){
        if(i%2==0) bin=0;
        else bin=1;
        for(int j=1;j<=i;j++){
            cout<<bin<<" ";
            bin=1-bin;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter pattern size : ";
    cin>>n;
    pattern_izer(n);
    return 0;
}
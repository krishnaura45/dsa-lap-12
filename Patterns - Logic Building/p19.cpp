#include<bits/stdc++.h>
using namespace std;


void pattern_izer(int n){
    for(int i=n;i>=1;i--){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            for(int j=(2*n)-(2*i);j>=1;j--){
                cout<<" ";
            }
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<"*";
            }
            for(int j=(2*n)-(2*i);j>=1;j--){
                cout<<" ";
            }
            for(int j=1;j<=i;j++){
                cout<<"*";
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
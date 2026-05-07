#include<bits/stdc++.h>
using namespace std;

// Inverted Triangle
void pattern_izer(int n){
    for(int i=n;i>0;i--){
        for(int j=n;j>=i;j--){
            cout<<" ";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }
        for(int j=n;j>=i;j--){
            cout<<" ";
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
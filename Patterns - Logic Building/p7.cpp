#include<bits/stdc++.h>
using namespace std;

// Triangle pattern
void pattern_izer(int n){
    for(int i=1;i<=n;i++){
        // spaces
        for(int j=n-1;j>=i;j--){
            cout<<" ";
        }

        // stars
        for(int k=1;k<=2*i-1;k++){
            cout<<"*";
        }

        // spaces
        for(int l=n-1;l>=i;l--){
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
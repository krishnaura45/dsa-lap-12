#include<bits/stdc++.h>
using namespace std;

// By defining function
void pattern_izer(int size){
    for(int i=size;i>0;i--){
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
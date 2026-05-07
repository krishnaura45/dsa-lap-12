#include<bits/stdc++.h>
using namespace std;

// By defining function
void pattern_izer(int n){
    int c=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<c<<" ";
            c+=1;
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
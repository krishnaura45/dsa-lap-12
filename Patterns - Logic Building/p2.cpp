#include<bits/stdc++.h>
using namespace std;

// Square Pattern
void pattern_izer(int size){
    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            cout<<"* ";
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
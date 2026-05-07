/*
C
C B
C B A
*/

// GFG - pattern 18

#include<bits/stdc++.h>
using namespace std;

void print23(int n){
    char ch='A'+n-1;
    for(int i=0;i<n;i++){
        for(char c=ch;c>=ch-i;c--){
            cout<<c<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    print23(n);
    return 0;
}
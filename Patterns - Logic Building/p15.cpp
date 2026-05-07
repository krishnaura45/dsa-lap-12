#include<bits/stdc++.h>
using namespace std;

void print15(int n){
    for(int i=n;i>=1;i--){
        for(char ch='A';ch<='A'+i-1;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    print15(n);
    return 0;
}
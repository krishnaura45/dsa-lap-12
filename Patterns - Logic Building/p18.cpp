#include<bits/stdc++.h>
using namespace std;

// Strivers - pattern 18
void print18(int n){
    char c = 'A'+n-1;
    for(int i=0;i<n;i++){
        for(char ch=c-i;ch<=c;ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    print18(n);
    return 0;
}
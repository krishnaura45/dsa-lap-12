#include<bits/stdc++.h>
using namespace std;

// ABCD right angled triangle
void pattern_izer(int n){
    for(int i=1;i<=n;i++){
        for(char ch='A';ch<='A'+i-1;ch++){
            cout<<ch<<" ";
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
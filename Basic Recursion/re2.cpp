// Print name N times using recursion
#include<bits/stdc++.h>
using namespace std;

void print(int i,int N){
    // Base condition
    if(i>N) return;

    // printing and function call (else block)
    cout<<"Krish"<<endl;
    print(i+1,N);
}

int main(){
    int n;
    cin>>n;
    print(1,n);
    return 0;
}
// Print 1 to N linearly
#include<bits/stdc++.h>
using namespace std;

// Using recursion
void print_r(int i,int N){
    if(i==0) return;

    cout<<i<<endl;    //....printing first
    print_r(i-1,N);   //....calling itself after
}

// Using Backtrack
void print_b(int i,int N){
    if(i>N) return;

    print_b(i+1,N);
    cout<<i<<endl;
    
}

int main(){
    int n;
    cin>>n;
    //print_r(n,n);
    print_b(1,n);
    return 0;
}
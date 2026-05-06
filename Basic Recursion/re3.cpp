// Print 1 to N linearly
#include<bits/stdc++.h>
using namespace std;

// Using recursion
void print_r(int i,int N){
    if(i>N) return;

    cout<<i<<endl;
    print_r(i+1,N);
}

// Using Backtrack
void print_b(int i,int N){
    if(i==0) return;

    print_b(i-1,N);
    cout<<i<<endl;
    
}

int main(){
    int n;
    cin>>n;
    //print_r(1,n);
    print_b(n,n);
    return 0;
}
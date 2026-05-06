// Fibonacci Number upto nth term (0 based indexing)
#include<bits/stdc++.h>
using namespace std;

int fibo(int N){
    if(N<=1)
        return N;
    
    // For N>1
    int num= fibo(N-1)+fibo(N-2);
    return num;   
}

int main(){
    int n;
    cin>>n;
    int f=fibo(n);
    cout<<f;
}
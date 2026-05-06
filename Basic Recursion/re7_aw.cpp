// Fibonacci number upto nth term (0 based indexing) using multiple recursion calls
#include<bits/stdc++.h>
using namespace std;

int fibo(int N){
    if(N<=1)
        return N;
    
    // For N>1
    int last=fibo(N-1);
    int slast=fibo(N-2);
    return last+slast;   
}

int main(){
    int n;
    cin>>n;
    int f=fibo(n);
    cout<<f;
}

// TC --> (2^n) that is, exponential
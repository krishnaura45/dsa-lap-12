// Sum of the first N natural numbers
#include<bits/stdc++.h>
using namespace std;

// Functional approach --> simpler than parameterised approach

int sumn(int N){
    if(N==1) return 1;
    int sum=N+sumn(N-1);
    return sum;
}

int main(){
    int n;
    cin>>n;
    int s=sumn(n);
    cout<<"Sum of first "<<n<<" natural nimbers is --> "<<s;
    return 0;
}
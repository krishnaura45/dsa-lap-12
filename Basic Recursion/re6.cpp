// Factorial of a number - two approaches --> Iterative (O(n),O(1)) and Recursive (O(n),O(n))
#include<bits/stdc++.h>
using namespace std;

int fact(int N){
    if(N==0) return 1;
    return N*fact(N-1);
}

int main(){
    int n;
    cin>>n;
    int f=fact(n);
    cout<<"Factorial of number "<<n<<" is --> "<<f;
    return 0;
}
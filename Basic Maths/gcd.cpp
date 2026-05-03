// ***** (Greatest Common Divisor / Highest Common Factor) *****
#include<bits/stdc++.h>
using namespace std;

void gcd_bf(int a,int b){
    int gcd=1;
    for(int i=1;i<=min(a,b);i++){
        if(a%i==0 && b%i==0){
            gcd=i;
        }
    }
    cout<<gcd;
}
// time complexity = O(min(a,b))

int gcd_opt(int a,int b){
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
}
// time complexity = O(min(a,b))

// Euclidean Theorem --> gcd(a,b) = gcd(a-b,b) if a>b
int gcd_euclidean(int a,int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
    }

    if(a==0) return b;
    else return a;
}
// time complexity = O(log (min(a,b))) , log base=phi

int main(){
    int a,b;
    cin>>a>>b;
    //gcd_bf(a,b);
    int hcf;
    //hcf=gcd_opt(a,b);
    hcf=gcd_euclidean(a,b);
    cout<<"GCD is "<<hcf;
    return 0;
}
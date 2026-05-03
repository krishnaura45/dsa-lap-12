#include<bits/stdc++.h>
using namespace std;
// to count digits in number which evenly divide it
void count(int N){
    int c=0,a=N;
        while(N>0){
            int dig=N%10;
            N=N/10;
            if(a%dig==0){
                c+=1;
            }
        }
    cout<<c;
}

int main(){
    int n;
    cin>>n;
    count(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Butterfly pattern
void pattern_izer(int n){
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {cout<<'*';}
        int sp=(2*n)-(2*i);
        for(int j=1;j<=sp;j++)
        {cout<<' ';}
        for(int j=1;j<=i;j++)
        {cout<<'*';}
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++)
        {cout<<'*';}
        int sp=(2*n)-(2*i);
        for(int j=1;j<=sp;j++)
        {cout<<' ';}
        for(int j=1;j<=i;j++)
        {cout<<'*';}
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
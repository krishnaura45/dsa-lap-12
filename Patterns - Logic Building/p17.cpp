#include<bits/stdc++.h>
using namespace std;

// Triangle pattern
void print17(int n){
    for(int i=1;i<=n;i++){
        // spaces
        for(int j=n-1;j>=i;j--){
            cout<<" ";
        }

        // characters or alphabets
        char ch='A';
        int N=2*i-1;   // no. of alphabets in ith row
        int b=N/2+1; // break point or symmetrical centre
        for(int k=1;k<=N;k++){
            if(k<b){
                cout<<ch;
                ch++;
            }
            else{
                cout<<ch;
                ch--;
            }
        }

        // spaces
        for(int l=n-1;l>=i;l--){
            cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    
    int n;
    cout<<"Enter pattern size : ";
    cin>>n;
    
    print17(n);
    return 0;
}
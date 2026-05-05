#include<bits/stdc++.h>
using namespace std;

// Character hashing
int main(){
    string s;
    cin>>s;

    // precompute
    int hash[256]={0};   // size =256 for all characters
    for(int i=0;i<s.length();i++){
        hash[s[i]]+=1;
    }

    // fetch
    int q;   // no. of queries
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<"Frequency of "<<ch<<" --> "<<hash[ch]<<endl;
    }

    return 0;
}
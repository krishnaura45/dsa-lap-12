#include<bits/stdc++.h>
using namespace std;

// Character hashing
int main(){
    string s;
    cin>>s;

    // precompute
    int hash[26]={0};   // size =26 for lower case letters
    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']+=1;
    }

    // fetch
    int q;   // no. of queries
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        cout<<"Frequency of "<<ch<<" --> "<<hash[ch-'a']<<endl;
    }

    return 0;
}
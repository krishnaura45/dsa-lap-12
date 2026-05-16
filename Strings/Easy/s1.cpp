// Remove outermost paranthesis
#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    s=s+" ";
    string w="",r="";
    int lc=0,rc=0;
    for(int i=0;i<s.length();i++){
       char c=s[i];
       if(c=='(') lc++;
       else rc++;

       if(lc!=rc){
           w=w+c;
           }
       else{
           string sw=w.substr(1,w.length()-1);
           r=r+sw;
           w="";
       }
    }
    return r;   
}

int main(){
    string st;
    getline(cin,st);
    string res=removeOuterParentheses(st);
    cout<<res;
    return 0;
}
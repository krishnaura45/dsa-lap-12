// Reverse words in string - II
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    s=s+" ";
    string w="",ns="";
    int i=0,cnt=0;
    while(i<s.length()){
        char c=s[i];
        if(c==' ' && cnt==0){
            //ignore any leading spaces
        }
        else if(c!=' '){
            cnt++;
            w=w+c;
        }
        else if(c==' ' && cnt!=0){
            // collecting word, ignoring in-between spaces
            if(s[i-1]!=' ') {
                ns=w+" "+ns;
                w="";
            }
            else ns=ns;
        }
        i++;
    }
    int len=ns.length();
    ns=ns.substr(0,len-1);
    return ns;
}

int main(){
    string st;
    getline(cin,st);
    string res=reverseWords(st);
    cout<<res;
    return 0;
}
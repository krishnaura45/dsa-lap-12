// Isomorphic strings
#include<bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;
        // Otherwise
        int l=s.length();
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                // problem comes here
                if((s[i]==s[j] && t[i]!=t[j]) || (s[i]!=s[j] && t[i]==t[j])){
                    return false;
                }
            }
        }
        return true;
    }

int main(){
    string s="egg";
    string t="cfk";
    bool res=isIsomorphic(s,t);
    cout<<res;
    return 0;
}
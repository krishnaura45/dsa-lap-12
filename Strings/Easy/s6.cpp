// Rotate String
#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string t) {
        if(s.length()!=t.length()) return false;
        // Otherwise
        int l=s.length();
        for(int i=1;i<=l;i++){
            // left rotate
            char temp=s[0];
            for(int j=1;j<l;j++){
                s[j-1]=s[j];
            }
            s[l-1]=temp;
            if(s==t) return true;
        }
        return false;
    }

int main(){
    string s,goal;
    cin>>s;
    cin>>goal;
    bool res=rotateString(s,goal);
    cout<<res;
    return 0;
}
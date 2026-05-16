// Largest odd number in a string
#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string s) {
        s=s+" ";
        int max=1;
        string st="",lon="";
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                char c=s[j];
                if(c!=' '){
                    st=st+c;
                    if(stoi(st)>=max && stoi(st)%2==1){
                        max=stoi(st);
                        lon=st;
                    }
                }
                else break;
            }
            st="";
        }
        return lon;
    }

int main(){
    string st;
    getline(cin,st);
    string res=largestOddNumber(st);
    cout<<res;
    return 0;
}
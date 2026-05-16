// Longest common prefix
#include<bits/stdc++.h>
using namespace std;

// One approach
string longestCommonPrefix(vector<string>& strs) {
        string lcp="";
        for(int j=0;j<strs[0].length();j++){
            char c=strs[0][j];
            lcp+=c;
            for(int k=1;k<strs.size();k++){
                if(lcp==strs[k].substr(0,j+1)){
                    // already added in common prefix
                    // nothing to do
                }
                else{
                    int l=lcp.length();
                    // Remove last character
                    lcp=lcp.substr(0,l-1);

                    // got the lcp so finish process
                    return lcp;
                }
            }
        }
        return lcp;
    }

// Another approach
string minimumLengthSubstring(vector<string> strs){
    string mls="";
    int min=INT_MAX;
    for(int i=0;i<strs.size();i++){
        int l=strs[i].length();
        if(l<min){
            min=l;
            mls=strs[i];
        }
    }
    return mls;
}
string longestCommonPrefix_2(vector<string>& strs) {
        string lcp="";
        string mins=minimumLengthSubstring(strs);
        for(int j=0;j<mins.length();j++){
            char c=strs[0][j];
            lcp+=c;
            for(int k=1;k<strs.size();k++){
                if(lcp==strs[k].substr(0,j+1)){
                    // already added in common prefix
                    // nothing to do
                }
                else{
                    int l=lcp.length();
                    // Remove last character
                    lcp=lcp.substr(0,l-1);

                    // got the lcp so finish process
                    return lcp;
                }
            }
        }
        return lcp;
    }

int main(){
    vector<string> strs={"fla","flower","flow"};
    // string res=longestCommonPrefix(strs);
    string res=longestCommonPrefix_2(strs);
    cout<<res;
    return 0;
}
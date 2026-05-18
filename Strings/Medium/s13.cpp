// Longest Palindromic Substring
#include<bits/stdc++.h>
using namespace std;

// brute --> time limit exceeded for 96/142 cases
string reverse(string s){
    string r;
    for(int i=0;i<s.length();i++){
        r=s[i]+r;
    }
    return r;
}

string longestPalindrome(string str) {
    int l=str.length();
    string lps;
    int maxl=0;
    for(int i=0;i<l;i++){
        string s,r;   // substring, reverse
        for(int j=i;j<l;j++){
            s=str.substr(i,j-i+1);
            r=reverse(s);
            if(s==r){
                int len=s.length();
                if(len>maxl){
                    maxl=max(len,maxl);
                    lps=s;
                }
            } 
        }
    }
    return lps;
}

// optimized brute --> TLE , passed 78/142 tcases
string longestPalindrome_2(string str){
    int len=str.length();
    string lps;
    int maxl=0;
    string r="";
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            string s=str.substr(i,j-i+1);
            r=str[j]+r;

            if(s==r){
                int l=s.length();
                if(l>maxl){
                    maxl=max(l,maxl);
                    lps=s;
                }
            } 
        }
        r="";
    }
    cout<<maxl<<endl;
    return lps;
}

// Optimal --> Using DP ---> MARKED
bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
    if(i == j){
        return dp[i][j] = true;
    }
    if(j-i == 1){
        if(s[i] == s[j]){
            return dp[i][j] = true;
        }
        else{
            return dp[i][j] = false;
        }
    }
    if(s[i] == s[j] && dp[i+1][j-1] == true){
        return dp[i][j] = true;
    } 
    else {
        return dp[i][j] = false;
    }
}

string longestPalindrome_3(string s) {
    int n = s.size();
    int startIndex = 0; int maxlen = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            solve(dp, i, j, s);
            if(dp[i][j] == true){
                if(j-i+1 > maxlen){
                    startIndex = i;
                    maxlen = j-i+1;
                }
            }
        }
    }
    return s.substr(startIndex, maxlen);
}

int main(){
    string st;
    cin>>st;
    string res=longestPalindrome_2(st);
    cout<<res;
    return 0;
}
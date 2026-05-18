// Maximum Nesting Depth of the Parantheses
#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int l=s.length();
    int maxd=INT_MIN;
    int c1=0,c2=0;
    for(int i=0;i<l;i++){
        int cd=c1-c2;  // depth of current char
        maxd=max(cd,maxd);
        if(s[i]=='(') c1++;
        else if(s[i]==')') c2++;
    }
    return maxd;
}

int main(){
    string s;
    cin>>s;
    int res=maxDepth(s);
    cout<<res;
    return 0;
}

// *** The depth of any character in the VPS is the ( number of left brackets before it ) - ( number of right brackets before it )
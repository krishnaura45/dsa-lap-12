// Implement Atoi --> marked
#include<bits/stdc++.h>
using namespace std;

// Failed approach
int myAtoi_b(string s) {
    int l=s.length();
    string r;
    int cnt=0;
    for(int i=0;i<l;i++){
        char c=s[i];
        if(c>='1' && c<='9') r+=c;
        else if(c=='+' || c=='-' && cnt==0){
            r=r+c;
            cnt=1;
        }
        else continue;
    }  

    int v=stoi(r);
    return v;
}

// Optimal approach
int myAtoi(string s) {
    int l=s.length();
    double num = 0;
    int i=0;

    // Ignore leading whitespaces
    while(s[i] == ' '){
        i++;
    }

    // process signs
    bool positive = s[i] == '+';
    bool negative = (s[i] == '-');
    if(positive==true) i++;    // positive == true ? i++ : i;
    if(negative==true) i++;    // negative == true ? i++ : i;

    // dealing with digits
    while(i < l && s[i] >= '0' && s[i] <= '9'){
        // calculating number
        num = num*10 + (s[i]-'0');
        i++;
    }

    if(negative==true) num=-num;  // num = negative ? -num : num;
    else num=num;

    // handling range or overflow case
    num = (num > INT_MAX) ? INT_MAX : num;
    num = (num < INT_MIN) ? INT_MIN : num;
    
    return int(num);
}

int main(){
    string s;
    cin>>s;
    int res=myAtoi(s);
    cout<<res;
    return 0;
}
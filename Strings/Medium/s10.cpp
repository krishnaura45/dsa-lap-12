// Roman to Integer
#include<bits/stdc++.h>
using namespace std;

// My way
int romanToInt_bf(string s) {
    int l=s.length();
    int value=0;
    for(int i=0;i<l;i++){
        char ch=s[i];
        if(ch=='I') value+=1;
        else if(ch=='V') value+=5;
        else if(ch=='X') value+=10;
        else if(ch=='L') value+=50;
        else if(ch=='C') value+=100;
        else if(ch=='D') value+=500;
        else if(ch=='M') value+=1000;
    }
    return value;
}

// Optimal way
int romanToInt(string s) {
    int l=s.length();
    int value=0;
    unordered_map<char,int> mpp;
    mpp['I']=1;
    mpp['V']=5;
    mpp['X']=10;
    mpp['L']=50;
    mpp['C']=100;
    mpp['D']=500;
    mpp['M']=1000;

    // unordered_map <char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    for(int i=0;i<l-1;i++){
        if(mpp[s[i]]>=mpp[s[i+1]]) value=value+mpp[s[i]];
        else value=value-mpp[s[i]];
    }
    value+=mpp[s[l-1]];

    return value;
}

/*int romanToInt_2(string s) {
    int l=s.length();
    int value=0;
    vector<pair<char,int>> vec;
    vec.push_back({"L",50});
    vec.push_back({"I",1});
    vec.push_back({"V",5});
    vec.push_back({"M",1000});
    vec.push_back({"C",100});
    vec.push_back({"D",500});
    vec.push_back({"X",10});
    
    for(auto it:vec){
        if(it.second >= (it+1).second) value=value + (it.second);
        else value=value - (it.second);
    }
    // value+=*((vec.end()-1).second);

    return value;
}*/

int main(){
    string s;
    cin>>s;
    int res=romanToInt(s);
    cout<<res;
    return 0;
}
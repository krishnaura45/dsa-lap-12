// Reverse words in a given string-I (simple)
// Given string : owl at night
// Output string : night at owl 
#include<iostream>
#include<string>
using namespace std;

void reverse_wis(string &s){
    s=s+" ";
    string w="",ns="";
    for(int i=0;i<s.length();i++){
        char c=s[i];
        if(c!=' '){
            w=w+c;
        }
        else{
            ns=w+" "+ns;
            w="";
        }
    }
    cout<<"Original  String : "<<s<<endl;
    cout<<"Resulting String : "<<ns<<endl;
}

int main(){
    string st;
    getline(cin,st);
    reverse_wis(st);
    return 0;
}
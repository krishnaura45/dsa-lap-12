// Valid anagram
#include<bits/stdc++.h>
using namespace std;

// My way
bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        // Otherwise
        int l=s.length();

        // calculating frequencies
        int freq1[26]={0},freq2[26]={0};
        for(int i=0;i<l;i++){
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]) return false;
        }
        return true;
}
// O(l+k), where l=length of each string and k=26

// another way
bool isAnagram2(string str1, string str2)
{
    // Both the strings must have equal length.
    if (str1.length() != str2.length())
    {
        return false;
    }

    // Sorting the strings.
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Comparing the sorted strings.
    return (str1 == str2);
}
// O(2l log l), where l=s.size=t.size

int main(){
    string s = "rat", t = "car";
    bool res=isAnagram(s,t);
    // bool res=isAnagram2(s,t);
    cout<<res;
    return 0;
}
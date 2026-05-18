// Sum of Beauty of all substrings
// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
#include<bits/stdc++.h>
using namespace std;

// First way --> TLE, 56/57 tcases passed
int beauty(string s){
    // hashmap for storing frequency of characters
    int freq[26]={0};
    for(char ch:s) freq[ch-'a']++;
    int maxf=INT_MIN,minf=INT_MAX;
    for(int i=0;i<s.length();i++){
        maxf=max(maxf,freq[s[i]-'a']);
        minf=min(minf,freq[s[i]-'a']);
    }
    return maxf-minf;
}

int beautySum(string str) {
    int n=str.length();
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string s=str.substr(i,j-i+1);
            sum=sum+beauty(s);
        }
    }
    return sum;
}
// O(n^2 * len(s)) => almost O(n^3)

// Optimal
int beautySum(string s) {
    int sum = 0; 
    int n = s.length();        
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++) {
            mp[s[j]]++; // storing characters of every possible substring
            int maxFreq = 0, minFreq = INT_MAX;
            // <--finding beauty of substring -->
            for (auto it : mp) {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }
            sum += (maxFreq - minFreq);
        }
    }
    return sum;
}

int main(){
    string s;
    cin>>s;
    int res=beautySum(s);
    cout<<res;
    return 0;
}
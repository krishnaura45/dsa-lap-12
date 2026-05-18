// Sort characters by frequency
#include<bits/stdc++.h>
using namespace std;

// My way - for lower case only
string freqSort(string s) {
    int l=s.length();
    int freq[26]={0};
    for(int i=0;i<l;i++){
        char c=s[i];
        freq[c-'a']++;
    }

    string w;
    char last;
    for(int i=0;i<l;i++){
        if(freq[s[i]]<freq[last]){
            w=w+s[i];
        }
        else{
            w=s[i]+w;
        }
        last=s[i];
    }
    return w;
}

// Optimal way
string frequencySort(string s) {
        // hashmap for storing frequency of characters
        unordered_map<char, int> map;
        for (char ch: s) map[ch]++;
        
        // To store characters in dec. freq fashion
        priority_queue<pair<int, char>> pq;
        for (auto pair: map) {
            pq.push({pair.second, pair.first});
        }

        string w;
        pair<int, char> curr;
        // Until the queue becomes empty
        while (!pq.empty()) {
            // store current character
            curr = pq.top();

            // removing it out FIFO
            pq.pop();

            // storing string like string w(3,'n') ==> "nnn"
            w.append(curr.first, curr.second);
        }
        return w;
}

int main(){
    string s;
    cin>>s;
    //string res=freqSort(s);
    string res=frequencySort(s);
    cout<<res;
    return 0;
}
// Count Substrings With K Different Characters
#include<bits/stdc++.h>
using namespace std;

// brute
int countDC(string s){
    set<char> st;
    for(char c:s) st.insert(c);
    return st.size();
}

int countSubStrings_1(string str, int k) 
{
    int len=str.length();

    if(k>len) return 0;
    // otherwise

    int cnt=0;
    string s;   // substring variable
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++){
            s=str.substr(i,j-i+1);
            if(countDC(s)==k) cnt++;
        }
    }
    return cnt;
}

// optimized
int countSubStrings_2(string s, int k){
    int n = s.length();
    int result = 0;

    // Loop through all possible starting positions of the substring (i)
    for (int i = 0; i < n; i++) {
        int count[26] = {0}; // Initialize an array to store character counts for 'a' to 'z'
        int distinctChars = 0; // Counter for distinct characters

        // Loop through all possible ending positions of the substring (j)
        for (int j = i; j < n; j++) {
            if (count[s[j] - 'a'] == 0) {
                distinctChars++; // If the character appears for the first time in the substring, increment distinctChars
            }
            count[s[j] - 'a']++; // Increment the count of the character in the array

            if (distinctChars == k) {
                result++; // If the distinct character count equals K, increment the result
            }
        }
    }
    return result;
}

// optimal ---> MARKED
// Helper function to count substrings with at most K different characters
int HELPER(const string& s, int K) {
    vector<int> count(26, 0); // Initialize an array to count characters (a-z)
    int i = 0, j = 0; // Initialize two pointers
    int currCount = 0; // Initialize a variable to store the count of different characters in the substring
    int result = 0; // Initialize a variable for the answer

    while (j < s.length()) {
        // Increase the count of the character at position j in the count array
        if (count[s[j] - 'a'] == 0) {
            currCount++; // If this is a new character, increment the current count
        }
        count[s[j] - 'a']++;

        // If the current count is greater than K, move the window
        while (currCount > K) {
            if (count[s[i] - 'a'] == 1) {
                currCount--; // If the character at position i is unique, decrement the current count
            }
            count[s[i] - 'a']--; // Decrease the count for the character at position i
            i++; // Move the left pointer to the right
        }

        // Add the number of substrings with at most K different characters to the result
        result += j - i + 1;
        j++; // Move the right pointer to the right
    }

    return result;
}

int countSubStrings_3(string s, int k){
    // Call the HELPER function for at most K different characters and subtract the result of at most K-1 different characters
    return HELPER(s, k) - HELPER(s, k - 1);
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int res=countSubStrings_3(s,k);
    cout<<res;
    return 0;
}
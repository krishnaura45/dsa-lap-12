// Longest Consecutive Sequence
#include<bits/stdc++.h>
using namespace std;

// linear search
bool ls(vector<int> arr,int num)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num) return true;
    }
    return false;
}

// Brute
int longestConsecutiveSequence(vector<int> &arr){
    int longest=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int x=arr[i];  // Selected sequence start
        int cnt=1;
        while(ls(arr,x+1)==true){
            cnt++;
            x=x+1;
        }
        longest=max(longest,cnt);
    }
    return longest;
}
// O(n^2),O(1)

// Better
int longestConsecutiveSequence_be(vector<int> &arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int longest=1;
    int last_smaller=INT_MIN;
    int cnt=0; // current count of consecutiveness
    for(int i=0;i<n;i++){
        if(arr[i]-1==last_smaller){
            cnt++;
            last_smaller=arr[i];
        }
        else if(arr[i]!=last_smaller){
            cnt=1;
            last_smaller=arr[i];
        }
        longest=max(longest,cnt);
    }
    return longest;
}
// O(nlogn) + O(n) , O(n) for array distortion otherwise O(1)

// Optimal -->>> marked
int longestConsecutiveSequence_op(vector<int> &arr){
    int n=arr.size();
    int longest=1;
    unordered_set<int> st;   // for least time complexity assuming there are no collisions
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
    }

    return longest;
}
// O(3n),O(n)

int main(){
    vector<int> arr={102,4,100,1,101,3,2,1,1};
    //int len=longestConsecutiveSequence(arr);
    //int len=longestConsecutiveSequence_be(arr);
    int len=longestConsecutiveSequence_op(arr);
    cout<< "Length of LCS : "<< len;
    return 0;
}
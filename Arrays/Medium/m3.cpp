// Majority element in an array (> n/2 times)
#include<bits/stdc++.h>
using namespace std;

// BRUTE 
int majorElement(vector<int> &a)
{
    int n=a.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==a[i]) cnt++;
        }
        if(cnt>n/2) return a[i];
    }
    return -1;
}
// O(n^2),O(1)

// BETTER --> using hashmap
int majorElement_be(vector<int> &a){
    int n=a.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    for(auto it:mpp){
        if(it.second>n/2) return it.first;
    }
    return -1;
}
// T.C --> O(nlogn) + O(n) => O(nlogn), 
// S.C --> O(n)

// OPTIMAL --> using Moore's Voting Algorithm
int majorElement_op(vector<int> &a){
    int n=a.size();
    int cnt=0;
    int el;
    for(int i=0;i<n;i++){
        if(cnt==0){
            el=a[i];
            cnt=1;
        }
        else if(a[i]==el) cnt++;
        else cnt--;
    }

    // verifying for major element
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==el) count++;
    }
    if(count>n/2) return el;
    else return -1;
}

int main(){
    vector<int> arr={2,7,5,2,7,5,7,7,7};
    //int ans=majorElement(arr);
    //int ans=majorElement_be(arr);
    int ans=majorElement_op(arr);
    cout<<"Majority element is "<<ans<<endl;
    return 0;
}

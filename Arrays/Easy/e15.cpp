// Find the number that appears once as others appears twice
#include<bits/stdc++.h>
using namespace std;

// BF
int findNumAppearingOnce(vector<int> &a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]==num) cnt++;
        }
        if(cnt==1) return num;
    }
    return -1;
}

// Better approach --> using hashing
int getSingleElement(vector<int> &a){
    int n=a.size();

    int maxi=a[0];
    for(int i=0;i<n;i++) maxi=max(maxi,a[i]);

    int hash[maxi+1]={0};
    for(int i=0;i<n;i++) hash[a[i]]++;

    for(int i=0;i<n;i++){
        if(hash[a[i]]==1) return a[i];
    }

    //This line will never execute if the array contains a single element.
    return -1;
}

// Better approach --> using map
int gSE(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Declare the hashmap and hash the given array:
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }

    return -1;
}

// OP
int fNAO(vector<int> &a){
    int n=a.size();

    int xorr=0;
    for(int i=0;i<n;i++) 
        xorr = xorr ^ a[i];
    return xorr;
}

int main(){
    vector<int> arr={1,1,2,2,4,5,3,4,3};
    //int ans=findNumAppearingOnce(arr);
    //int ans=getSingleElement(arr);
    int ans=gSE(arr);
    //int ans=fNAO(arr);
    cout<<"Number appearing once --> "<<ans<<endl;
    return 0;
}
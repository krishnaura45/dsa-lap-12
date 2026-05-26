// Find the first and last occurence of a given number x
#include<bits/stdc++.h>
using namespace std;

// Brute force --> linear search modification
vector<int> occurence(vector<int> arr,int x){
    int n=arr.size();
    int first=-1,last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            if(first==-1) first=i;
            last=i;
        }
    }
    return {first,last};
}

// Optimal --> using binary search implementations i.e lb & ub
vector<int> fl_occurence(vector<int> arr,int x){
    int n=arr.size();

    // Calculating lower bound and upper bound
    int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();

    // if the number is not present
    if(lb==n || arr[lb]!=x)
     return {-1,-1};

    else
     return {lb,ub-1};
}

// Most optimal --> using plain binary search modification
int first_occ(vector<int> arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            first=mid;
            high=mid-1;
        }

        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return first;
}

int last_occ(vector<int> arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int last=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            last=mid;
            low=mid+1;
        }

        else if(arr[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return last;
}

vector<int> first_last(vector<int> arr,int x){
    int first=first_occ(arr,x);
    if(first==-1) return {-1,-1};
    int last=last_occ(arr,x);
    return {first,last};
}

int main(){
    vector<int> arr={2,4,6,8,8,8,11,13};
    int x=8;   // inputs - 8,10,11
    // vector<int> ans=occurence(arr,x);
    // vector<int> ans=fl_occurence(arr,x);
    vector<int> ans=first_last(arr,x);
    for(auto it:ans) cout<<it<<"\t";
    return 0;
}
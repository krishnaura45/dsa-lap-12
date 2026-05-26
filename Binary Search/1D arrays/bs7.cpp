// Count occurences of a number in an array
#include<bits/stdc++.h>
using namespace std;

// Brute force --> linear search modification

// Optimal --> using binary search implementations i.e lb & ub

// Most optimal for interviews --> using plain binary search modification
int first_occ(vector<int> arr,int x){
    int n=arr.size();
    int low=0,high=n-1;
    int first=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==x){
            first=mid;
            // Reducing search space for first occ to left half
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

int count_occurences(vector<int> arr,int x){
    int first=first_occ(arr,x);
    if(first==-1) return 0;
    int last=last_occ(arr,x);
    return last-first+1;
}
// O(2log n)

int main(){
    vector<int> arr={2,4,6,8,8,8,11,13};
    int x=8;   // inputs - 8,10,11
    int ans=count_occurences(arr,x);
    cout<<ans;
    return 0;
}
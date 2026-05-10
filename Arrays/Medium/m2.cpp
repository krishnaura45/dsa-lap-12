// Sort an array of 0's,1's and 2's
#include<bits/stdc++.h>
using namespace std;

// BRUTE --> using merge sort
// O(nlogn),O(n)

// BETTER --> using count of values
vector<int> sort_zot_be(vector<int> &a){
    int n=a.size();
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) c0++;
        else if(a[i]==1) c1++;
        else c2++;
    }
    for(int i=0;i<c0;i++) a[i]=0;
    for(int i=c0;i<c0+c1;i++) a[i]=1;
    for(int i=c0+c1;i<n;i++) a[i]=2;

    return a;

}
// O(2n),O(1)

// OPTIMAL solution --> using DNF algorithm
vector<int> sort_zot_op(vector<int> &a){
    int n=a.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid],a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1) mid++;
        else{
            swap(a[mid],a[high]);
            high--;
        }
    }

    return a;
}
// O(n),O(1)

int main(){
    vector<int> arr={0,1,2,0,1,2,1,2,0,0,0,1};
    vector<int> ans=sort_zot_op(arr);
    for(auto it:ans) cout<<it<<" ";
    return 0;
}
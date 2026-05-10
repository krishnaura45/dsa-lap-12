// Variety 2 --> Rearrange by sign if unequal positives and negatives
#include<bits/stdc++.h>
using namespace std;

// Brute force -> modified version of the previous vareity
void rearrange_bf(vector<int> &arr,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    int cp=pos.size(),cn=neg.size();
    int ind;
    if(cp>cn){
        for(int i=0;i<cn;i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }
        ind=2*cn;
        for(int i=cn;i<cp;i++){
            arr[ind]=pos[i];
            ind++;
        }
    }
    else{
        for(int i=0;i<cp;i++){
            arr[2*i]=pos[i];
            arr[2*i+1]=neg[i];
        }   
        ind=2*cp;
        for(int i=cp;i<cn;i++){
            arr[ind]=neg[i];
            ind++;
        }
    }
}
// O(2n),O(n)

int main(){
    vector<int> arr={3,-1,-2,-5,2,-4};
    int n=arr.size();
    rearrange_bf(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
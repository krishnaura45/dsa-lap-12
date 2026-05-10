// Rearrange Array Elements by Sign (+ - + -)
// Vareity 1 --> Array containing even no. of elements will be given in which equal no. of positive and negative no's will be there.
#include<bits/stdc++.h>
using namespace std;

void rearrange_bf(vector<int> &arr,int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0;i<n;i++){
        if(arr[i]>0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    for(int i=0;i<n/2;i++){
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
}
// O(3n/2),O(n)

vector<int> rearrange_op(vector<int> &arr,int n){
    int pos=0,neg=1;

    // Define array for storing the ans separately.
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            ans[pos]=arr[i];
            pos=pos+2;
        }
        else if(arr[i]<0){
            ans[neg]=arr[i];
            neg=neg+2;
        }
    }
    return ans;
}
// O(n),O(n)

int main(){
    vector<int> arr={3,1,-2,-5,2,-4};
    int n=arr.size();
    //rearrange(arr,n);
    //for(int i=0;i<n-1;i++) cout<<arr[i]<<" ";
    vector<int> ans=rearrange_op(arr,n);
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
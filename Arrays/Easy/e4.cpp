// Remove duplicates in-place from sorted array OR
// Modify array and return number of unique elements in the array

#include<bits/stdc++.h>
using namespace std;

// brute force approach -> using set
int counter_bf(vector<int> &arr,int n){
    // First pass
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    
    int index=0;
    for(auto it:st){
        arr[index]=it;
        index++;
    }

    return index;
}

// optimal solution -> using two pointer approach
int counter_op(vector<int> &arr,int n){
    int i=0,j=1;
    while(j<n){
        if(arr[j]==arr[i]){
            // equivalent
            j++;
        }
        else{
            i++;
            arr[i]=arr[j];
            j++;
        }
    }
    return i+1;
}

int main(){
    vector<int> a={1,1,2,2};
    int n=a.size();
    //int num=counter_bf(a,n);
    int num=counter_op(a,n);
    cout<<"Number of unique elements : "<<num;
    return 0;
}
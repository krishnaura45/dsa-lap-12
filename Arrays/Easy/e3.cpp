// Check if array is sorted in non-descending order
#include<bits/stdc++.h>
using namespace std;

bool check_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]) return false;  // reverse condition
    }
    return true;
}

int main(){
    vector<int> a={1,2,1,3,4};
    bool result=check_sort(a);
    if(result==1) cout<<"Array is sorted"<<endl;
    else cout<<"Array is not sorted"<<endl;
    return 0;
}
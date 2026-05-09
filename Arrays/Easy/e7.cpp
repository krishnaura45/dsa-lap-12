// Right rotate an array by one place
#include<bits/stdc++.h>
using namespace std;

void right_rotate(int arr[],int n){
    int temp=arr[n-1];
    for(int i=n-2;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
}

int main(){
    int n=5;
    int a[n]={1,2,3,4,5};

    right_rotate(a,n);
    cout<<"Array after right rotation by one place ->"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}

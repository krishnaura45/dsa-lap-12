// Left rotate an array by one place
#include<bits/stdc++.h>
using namespace std;

void left_rotate(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    left_rotate(a,n);
    cout<<"Array after left rotation by one place ->"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
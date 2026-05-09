// Left rotate an array by k places
#include<bits/stdc++.h>
using namespace std;

// Brute force method --> time complexity = O(n+k), space complexity = O(k)
void left_rotate(int arr[],int n,int k){
    k=k%n;

    // Store first k elements in temporary array
    int temp[k];
    for(int i=0;i<k;i++) temp[i]=arr[i];

    // Shifting 
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }

    // Put back temp
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    }
}

// Optimal method --> time complexity = O(2n), space complexity = O(1)
void left_rotate_op(int arr[],int n,int k){
    k=k%n;
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int k;
    cin>>k;

    //left_rotate(a,n,k);
    left_rotate_op(a,n,k);
    cout<<"Array after left rotation by "<<k<<" places ->"<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}

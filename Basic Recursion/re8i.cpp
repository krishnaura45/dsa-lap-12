// Reverse an array - using two variables without recursion
#include<bits/stdc++.h>
using namespace std;

void reverse(int l,int r,int arr[]){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

void printArray(int arr[], int n) {
   cout << "The reversed array is --> " << endl;
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    reverse(0,n-1,arr);
    printArray(arr,n);
    return 0;
}
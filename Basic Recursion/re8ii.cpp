// Reverse an array - using one variable without recursion
#include<bits/stdc++.h>
using namespace std;

void reverse(int i,int arr[],int n){
    while(i<n-i-1){
        swap(arr[i],arr[n-i-1]);
        i++;
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
    reverse(0,arr,n);
    printArray(arr,n);
    return 0;
}
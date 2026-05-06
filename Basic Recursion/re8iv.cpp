// Reverse an array - with recursion
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

//Function to reverse array using recursion
void reverseArray(int i,int arr[],int n) {
   if (i>=n/2) return;
   swap(arr[i], arr[n-i-1]); 
   reverseArray(i+1,arr,n);
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   reverseArray(0,arr,n);
   printArray(arr, n);
   return 0;
}
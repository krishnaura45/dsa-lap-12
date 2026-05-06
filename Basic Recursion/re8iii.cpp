// Reverse an array - with recursion
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
   for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
   }
}

//Function to reverse array using recursion
void reverseArray(int arr[], int start, int end) {
   if (start < end) {
      swap(arr[start], arr[end]);
      reverseArray(arr, start + 1, end - 1);
   }
}

int main() {
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
   reverseArray(arr, 0, n - 1);
   printArray(arr, n);
   return 0;
}

/*...Two more approaches are there to reverse an array -->
1. Using an extra array
2. Using library function
*/
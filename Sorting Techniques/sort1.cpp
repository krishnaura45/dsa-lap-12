// Selection Sort
// This algorithm is all about selecting minimum element from the unsorted array and swapping it with the first position element at each step.

/*
Example : 13,46,24,52,20,9
step 1: 9,46,24,52,20,13   Now 9 comes in sorted array and the others are still in unsorted array
step 2: 9,13,24,52,20,46   Now 9,13 comes in sorted array and the others are still in unsorted array
.
.
step 5: 9,13,20,24,46,52   Array is sorted
*/

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[mini]) mini=j; 
        }
        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;      // or direct--> swap(arr[i],arr[mini]);
    }
    cout<<"Array after selection sort :";
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    selection_sort(arr,n);
    return 0;
}

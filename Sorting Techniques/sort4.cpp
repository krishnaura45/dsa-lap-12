// Merge Sort -> Divide and Merge algorithm
// it divides the given array into equal parts and then merges the 2 sorted parts. 

#include<bits/stdc++.h>
using namespace std;

//low = leftmost index of the array
//high = rightmost index of the array
//mid = Middle index of the array 

void merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    // Insert from temp array to original array
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    } 
}

void merge_sort(vector<int> &arr,int low,int high)  // recursive function
{
    if(low>=high) return;    // base case
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main(){
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5}  ;
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;

    merge_sort(arr, 0, n - 1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "  ;
    }
    cout << endl;
    return 0;
}
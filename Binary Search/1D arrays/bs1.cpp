// Binary Search --> Searching algorithm which works in a limited search space for sorted area

// Real life example --> dictionary search - split into half
// Coding problem --> arrays

#include<bits/stdc++.h>
using namespace std;

// Iterative code --> O(log b2 (n))
int binary_search_iter(vector<int> &arr,int num){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(arr[mid]==num) return mid;
        else if(arr[mid]<num) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

// Recursive code --> O(log b2 (n))
int binary_search_rec(vector<int> &arr,int low,int high,int num){

    // To chech if the search space is exhausted and element is not found
    if(low>high) return -1;

    // Calculate middle element
    int mid=(high+low)/2;
    if(arr[mid]==num) 
     return mid;
    else if(arr[mid]<num) 
     return binary_search_rec(arr,mid+1,high,num);
    else
     return binary_search_rec(arr,low,mid-1,num);
}

int binarySearch(vector<int> &arr,int target){
    return binary_search_rec(arr,0,arr.size()-1,target);
}

// Driver function
int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 15;
    //int ind = binary_search_iter(a, target);
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

// Overflow case --> When search space is extended to INT_MAX, it might happen that search space contains only one element i.e. INT_MAX at some point then the integer variable 'mid' can't store 2*INT_MAX..
// Solutions --> 
// a) declare mid as long long, 
// b) mid = low + (high-low)/2
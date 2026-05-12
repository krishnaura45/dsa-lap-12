// Count Inversions --? count pairs such that If i<j then arr[i] > arr[j]
#include<bits/stdc++.h>
using namespace std;

// Brute
int countInversions(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}

// Optimal --> Intution of merge sort
int merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int cnt=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            cnt+= (mid-left+1);
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

    return cnt;
}

int merge_sort(vector<int> &arr,int low,int high)  // recursive function
{
    int cnt=0;
    if(low>=high) return cnt;    // base case
    int mid=(low+high)/2;
    cnt+= merge_sort(arr,low,mid);
    cnt+= merge_sort(arr,mid+1,high);
    cnt+= merge(arr,low,mid,high);
    return cnt;
}

int countInversions_op(vector<int> &arr){
    int n=arr.size();
    return merge_sort(arr,0,n-1);
}

int main(){
    vector<int> arr={5,3,2,4,1};
    // int ans=countInversions(arr);
    int ans=countInversions_op(arr);
    cout<<ans;
    return 0;
}
// Reverse pairs --> count pairs such that if i<j then arr[i] > 2*arr[j]
#include<bits/stdc++.h>
using namespace std;

// Brute
int reversePairs(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]> 2*arr[j]) cnt++;
        }
    }
    return cnt;
}

// Optimal
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

int countPairs(vector<int> &arr,int low,int mid,int high){
    int cnt=0;
    int right=mid+1;
    for(int i=low;i<=mid;i++){
        while(right<=high && arr[i]>2*arr[right]){
            right++;
        }
        cnt+= right-(mid+1);
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
    cnt+= countPairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int reversePairs_op(vector<int> &arr){
    int n=arr.size();
    return merge_sort(arr,0,n-1);
}

int main(){
    vector<int> arr={40,25,19,12,9,6,2};
    int ans=reversePairs_op(arr);
    //int ans=countInversions_op(arr);
    cout<<ans;
    return 0;
}
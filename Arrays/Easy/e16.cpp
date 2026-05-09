// Longest Subarray with given Sum K (Zero and Positives)
#include<bits/stdc++.h>
using namespace std;

// Optimized BF --> simplest
int findLongestSubarray_bf(vector<int> &a,int k){
    int n=a.size();
    
    int len=0;  // length variable for longest subarray
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}

// Optimal approach --> using two pointer
int findLongestSubarray_op(vector<int> &a,long long k){
    int left=0,right=0;
    long long sum=a[0];
    int maxLen=0;
    int n=a.size();
    while(right<n){
        while(left<=right && sum>k){
            sum=sum-a[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
        if(right<n) sum=sum+a[right];
    }
    return maxLen;
}

int main(){
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    vector<int> arr2={2,0,0,3,1};
    int K=4;
    /*  
    int ans1=findLongestSubarray_bf(arr,K);
    int ans2=findLongestSubarray_bf(arr2,K);   
    */
    int ans1=findLongestSubarray_op(arr,K);
    int ans2=findLongestSubarray_op(arr2,K); 
    
    cout<<"Length of longest subarray for first array with sum "<<K<<" --> "<<ans1<<endl;
    cout<<"Length of longest subarray for second array with sum "<<K<<" --> "<<ans2<<endl;

    return 0;
}
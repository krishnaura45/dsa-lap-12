// Maximum Subarray Sum
#include<bits/stdc++.h>
using namespace std;

// Brute
int maxSubSum_bf(vector<int> &arr){
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
                maxi=max(maxi,sum);
            }
        }
    }
    return maxi;
}

// Better
int maxSubSum_be(vector<int> &arr){
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            maxi=max(maxi,sum);    
        }
    }
    return maxi;
}

// Optimal --> Kadane's algorithm
int maxSubSum_op(vector<int> &arr){
    int n=arr.size();
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxi=max(sum,maxi);
        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

// Follow up --> There might be more than one subarray with the maximum sum. We need to print any of them.
int maxSubarraySum(vector<int> &arr) {
    int n=arr.size();
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    int ans=maxSubSum_bf(arr);
    //int ans=maxSubSum_be(arr);
    //int ans=maxSubSum_op(arr);
    //int ans=maxSubarraySum(arr);
    cout<<"Maximum subarray sum : "<<ans;
    return 0;
}
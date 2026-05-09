// Find the missing number
#include<bits/stdc++.h>
using namespace std;

// BRUTE FORCE Solution
int missingNumber(vector<int>&a, int N) {
    // Outer loop that runs from 1 to N:
    for (int i = 1; i <= N; i++) {

        // flag variable to check if an element exists
        int flag = 0;

        //Search the element using linear search:
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                // i is present in the array:
                flag = 1;
                break;
            }
        }

        // check if the element is missing
        //i.e flag == 0:

        if (flag == 0) return i;
    }

    // The following line will never execute.
    // It is just to avoid warnings.
    return -1;
}
// O(n^2),O(1)

// BETTER Solution --> using hashing 
int missing(vector<int> &arr,int N){
    int hash[N+1]={0};
    for(int i=0;i<N-1;i++) hash[arr[i]]+=1;
    for(int j=1;j<=N;j++){
        if(hash[j]==0) return j;
    }

    return -1;
}
// O(2n),O(n)

// OPTIMAL Solution --> using summation
int miss(vector<int> &arr,int N){
    int s1=(N*(N+1))/2;
    int s2=0;
    for(int i=0;i<N-1;i++) s2=s2+arr[i]; 
    int num=s1-s2;
    return num;
}
// O(n),O(1)

// Another optimal using XOR --> more better than the first
// 2^2 = 0 and 0^2 = 2

// Main function
int main()
{
    int N = 6;
    vector<int> a = {1, 2, 4, 5,3};
    //int ans = missingNumber(a, N);
    //int ans=missing(a,N);
    int ans=miss(a,N);

    cout << "The missing number is: " << ans << endl;
    return 0;
}

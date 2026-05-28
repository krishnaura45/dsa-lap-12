// Find square root of a number in log n --> floor of sqrt of number
// We have to search an answer in a particular range..
// In this case, range is [1,n]
// BS can always be applied on cases where answers can be found valid until a certain limit and after thet they are wrong

// PATTERN -1 (BS On ANSWERS)

#include<bits/stdc++.h>
using namespace std;

// Linear search
int sroan(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        if(i*i<=n) ans=i;
        else break;
    }
    return ans;
}

// Binary search
int sroan_op(int n){
    int ans=1;
    int low=1,high=n;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=n){
            // may be the answer
            ans=mid;
            // look on the right for better
            low=mid+1;
        }
        else{
            // go on left
            high=mid-1;
        }
    }
    return ans;     // return high;
}

int main(){
    int n=36;  // 25,28,35,36
    // int sr=sroan(n);
    int sr=sroan_op(n);
    cout<<"Square root of "<<n<<" is "<<sr;
    return 0;
}
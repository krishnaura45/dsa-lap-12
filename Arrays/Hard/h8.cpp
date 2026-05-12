// Find the missing and repeating number
#include<bits/stdc++.h>
using namespace std;

// Brute / Extreme naive
vector<int> missingRepeat(vector<int> &arr){
    // to store repeating and missing number
    int missing=-1;
    int repeating=-1;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int num=i+1;
        int cnt=0;
        for(int j=0;j<n;j++){
            if(num==arr[j]) cnt++;
        }
        if(cnt==2) repeating=num;
        else if(cnt==0) missing=num;

        if(repeating!=-1 && missing!=-1) break;
    }
    return {repeating,missing};
}
// O(n^2),O(1)

// Better --> Hashing
vector<int> missingRepeat_be(vector<int> &arr){
    int n=arr.size();
    int hash[n+1]={0};
    int missing=-1,repeating=-1;
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hash[i]==0) missing=i;
        else if(hash[i]==2) repeating=i;
    }
    return {repeating,missing};
}
// O(2n),O(n)

// Optimal-1
vector<int> missingRepeat_o1(vector<int> a) {
    long long n = a.size(); // size of the array

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;     // sum of n natural numbers
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;   // sum of squares of n natural numbers

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += (long long)a[i];
        S2 += (long long)a[i] * (long long)a[i];
    }

    //S-Sn = X-Y: where x --> repeating and y --> missing
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}
// O(n), O(1)

// Optimal-2

int main(){
    vector<int> arr={2,4,3,6,5,5};
    // vector<int> ans=missingRepeat(arr);
    // vector<int> ans=missingRepeat_be(arr);
    vector<int> ans=missingRepeat_o1(arr);
    cout<<"Repeating number : "<<ans[0]<<endl;
    cout<<"Missing number : "<<ans[1];
    return 0;
}
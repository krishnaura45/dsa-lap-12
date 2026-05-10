// Stock Buy and Sell
#include<bits/stdc++.h>
using namespace std;

int maxProfit_bf(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
            maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        }

    return maxPro;
}
// O(n^2),O(1)

int maxProfit_op(vector<int> &arr){
    int n=arr.size();
    int max_profit=0;
    int min_price=INT_MAX;  // for maintaining minimum buying price
    int s_price;            // for finding optimum selling price
    for(int i=0;i<n;i++){
        if(arr[i] < min_price){
            min_price=arr[i];
        }
        if(max_profit < arr[i]-min_price){
            max_profit=arr[i]-min_price;
            s_price=arr[i];
        }
    }
    return max_profit;
}
// O(n),O(1)

int main() {
    vector<int> arr = {7,2,5,6,3,1};
    //int maxPro = maxProfit_bf(arr);
    //cout << "Max profit is: " << maxPro << endl;
    int ans = maxProfit_op(arr);
    cout << "Max Profit is: " << ans << endl;
    return 0;
}
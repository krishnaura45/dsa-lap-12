// Minimize the max distance between gas stations
// Note : Answers within 10^-6 of the actual answer will be accepted
#include<bits/stdc++.h>
using namespace std;

// APP1 - brute
double maxdistance(vector<int> arr,int k){
    int n=arr.size();
    int howMany[n-1]={0};   // counter array for sections [0,0,0]
    for(int gasStation=1;gasStation<=k;gasStation++){
        double maxSec=-1; // to store section with max length
        int maxInd=-1;   // index of section with max length
        for(int i=0;i<n-1;i++){
            double diff=arr[i+1]-arr[i];
            double secLen=diff/(double)(howMany[i]+1);
            if(secLen>maxSec){
                maxSec=secLen;
                maxInd=i;
            }
        }
        howMany[maxInd]++;
    }

    double maxAns=-1;
    for(int i=0;i<n-1;i++){
        double diff=arr[i+1]-arr[i];
        double secLen=diff/(double)(howMany[i]+1);
        maxAns=max(maxAns,secLen);
    }
    return maxAns;
}
// O(k*n) + O(n)

// APP2 - better => using priority queue
double maxdistance_pq(vector<int> arr,int k){
    int n=arr.size();
    priority_queue<pair<double,int>> pq;
    vector<int> howMany(n-1,0);    // like a hash counter

    // To insert lengths of all intermediate sections between given / existing gas stations into pq
    for(int i=0;i<n-1;i++){
        pq.push({arr[i+1]-arr[i],i});
    }

    // Pick and place k gas stations
    for(int gasSt=1;gasSt<=k;gasSt++){
        auto tp=pq.top();
        pq.pop();
        int secInd=tp.second;

        //insert the current gas station:
        howMany[secInd]++;

        double diff = arr[secInd + 1] - arr[secInd];
        double newSecLen = diff / (double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }
    return pq.top().first;
}
// O(nlogn) + O(klogn)

// APP3 - optimal => using binary search
// To count no. of stations required
int count_stations(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);   // count possible sections
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;     // no. of stations= sections-1
        }
        cnt += numberInBetween;
    }
    return cnt;
}

// bs
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = count_stations(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}
// Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.

int main(){
    // vector<int> arr={1,13,17,23};
    // int k=5;
    // double ans=maxdistance(arr,k);
    // cout<<"The minimum possible max distance between gas stations will be: "<<ans;
    
    vector<int> arr={1,2,3,4,5};
    int k=4;
    double ans=maxdistance_pq(arr,k);
    // double ans=minimiseMaxDistance(arr,k);
    cout<<"The minimum possible max distance between gas stations will be: "<<ans;
    return 0;
}
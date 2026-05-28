// Koko eating bananas
// PS:
// A monkey is given ‘n’ piles of bananas, whereas the ‘ith’ pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

#include<bits/stdc++.h>
using namespace std;

// To calculate max of array
int maximum(vector<int> arr){
  int n=arr.size();
  int max = arr[0];
  for (int i = 0; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

// To calculate total time to eat bananas
int ttc(vector<int> arr,int hourly)    // hourly is i bananas per hour
{
    int total_time=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        total_time+=ceil(double(arr[i]) / double(hourly));
    }
    return total_time;
}

// Linear Search way

int keb(vector<int> arr,int h){
    int req_time=0;
    for(int i=1;i<=maximum(arr);i++){
        req_time=ttc(arr,i);
        if(req_time<=h)
         return i;
    }
}
// O(max(arr)*n)

// Binary search way
int keb_bs(vector<int> arr,int h){
    int n=arr.size();
    int ans=1;
    int low=1,high=maximum(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int time_taken=ttc(arr,mid);
        if(time_taken<=h){
            // May be an answer
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;      // return low;
}
// O(n*log(max(arr)))

int main(){
    // vector<int> piles={3,6,7,11};
    // int hours=8;
    // int k=keb(piles,hours);

    vector<int> piles={3,6,7,11,15,10};
    int hours=10;
    int k=keb_bs(piles,hours);
    cout<<"Speed of eating should be "<<k<<" bananas per hour";
    return 0;
}
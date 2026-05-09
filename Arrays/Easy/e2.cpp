// Second largest element in an array
#include<bits/stdc++.h>
using namespace std;

// Brute force approach
int find_sl_bf(vector<int> &arr){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int largest=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(arr[i]!=largest) return arr[i];
    }
}

// Better approach
int find_sl_be(vector<int> &arr){
    int n=arr.size();
    if(n<2)
        return -1;
    
    int max = arr[0];
    int sl=-1;
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) max=arr[i];
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]>sl && arr[i]!=max)
            sl=arr[i];
    }

    return sl;
}

// Optimal approach
int find_sl_op(vector<int> &arr){
    int n=arr.size();
    int l=arr[0];
    int sl=-1;     // assuming no negative numbers in array, if are then sl=INT_MIN
    for(int i=1;i<n;i++)
        if(arr[i]>l){
            sl=l;
            l=arr[i];
        }
        else if(arr[i]<l && arr[i]>sl){
            sl=arr[i];
        }
    return sl;
}

int main(){
  vector<int> arr= {2,5,1,4,3,0};
  // int sl = find_sl_bf(arr);
  // int sl = find_sl_be(arr);
  int sl = find_sl_op(arr);
  cout << "The second largest element in the array is: " << sl << endl;
  return 0;
}
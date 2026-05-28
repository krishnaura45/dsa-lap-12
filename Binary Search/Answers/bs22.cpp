// Agressive cows
// cows>=2 (bound)
#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> arr,int dist,int cows){   // dist is the variable minimum distance
    int n=arr.size();
    // first cow can always be placed at stall[0]
    int c=1;           // no. of cows placed in current scenario
    int last=arr[0];   // position variable for previous cow placed
    for(int i=1;i<=n-1;i++){
        if(arr[i]-last>=dist){
            c++;
            last=arr[i];
        }
        if(c>=cows) return true;
    }
    return false;
}

// LS way
int agressiveCows(vector<int> arr,int n,int cows){
    sort(arr.begin(),arr.end());
    // if there are two cows only then maximum distance is max-min
    // therefore range=[1,max(arr)-min(arr)]
    for(int i=1;i<=arr[n-1]-arr[0];i++){
        if(canWePlace(arr,i,cows)==true) continue;
        else return (i-1);
    }
}
// O(nlogn) + O(n*(max-min))

// BS way
int agressiveCows_bs(vector<int> stalls,int cows){
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        bool res=canWePlace(stalls,mid,cows);
        if(res==true){
            // may be an answer but look for better on the right
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}
// O(nlogn) + O(n*log2 (max-min))

int main(){
    vector<int> stalls={0,3,4,7,10,9};
    int n=stalls.size(),cows=4;
    // int ans=agressiveCows(stalls,n,cows);
    int ans=agressiveCows_bs(stalls,cows);
    cout<<"The maximum possible minimum distance between two cows is: "<<ans;
    return 0;
}
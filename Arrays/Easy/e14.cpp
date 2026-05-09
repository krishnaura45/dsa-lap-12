// maximum consecutive ones
#include<bits/stdc++.h>
using namespace std;

int findMaxConsOnes(vector<int> &a){
    int max=0;
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==1){
            cnt++;
            if(max<cnt) max=cnt;
        }
        else{
            cnt=0;
        }
    }
    return max; 
}

int main(){
    vector<int> nums={1,1,0,1,1,1,0,1};
    int ans=findMaxConsOnes(nums);
    cout<<"Maximum number of consecutive ones --> "<<ans<<endl;
    return 0;
}
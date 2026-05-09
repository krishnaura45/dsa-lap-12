// Move zeros to end
#include<bits/stdc++.h>
using namespace std;

// Brute Force solution
void zerosToEnd_bf(int arr[],int n) {

        vector<int> temp;
        for (int i=0;i<n;i++){
            if (arr[i]!=0){
                temp.push_back(arr[i]);
            }
        }

        int x=temp.size();
       
        for(int i=0;i<x;i++){
            arr[i]=temp[i];
        }

        for(int i=x;i<n;i++)
        {
            arr[i]=0;
        }
    }

// Optimal solution --> using two pointer approach
void zerosToEnd_op(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    
    // all non zero numbers
    if(j==-1){
        return;
    }

    else{
        for(int i=j+1;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
        }
        return;
    }
    
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    zerosToEnd_op(arr,n);

    cout<<"Resulting array -->"<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    
}
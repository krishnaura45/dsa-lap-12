// Infinite Recursion
#include<bits/stdc++.h>
using namespace std;

void print(){
    // No Base condition
    // printing and function call 
    cout<<1<<endl;
    print();
}

int main(){
    
    print();
    return 0;
}
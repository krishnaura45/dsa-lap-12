#include<bits/stdc++.h>
using namespace std;

void printDivisorsBruteForce(int n){

	cout<<"The Divisors of "<<n<<" are:"<<endl;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			cout << i << " ";
	
	cout << endl;
}

void printDivisorsOptimal(int n){
    vector<int> v;   // Defining a vector container to store divisors
    cout<<"The Divisors of "<<n<<" are:"<<endl;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0){
			v.emplace_back(i);
			if(i != n/i) v.emplace_back(n/i);
		}
    
    // Sorting the divisors in vector
	sort(v.begin(),v.end());
    // Printing
    for(auto it:v) cout<<it<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    //printDivisorsBruteForce(n);
    printDivisorsOptimal(n);
    return 0;
}
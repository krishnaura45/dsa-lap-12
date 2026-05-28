// Book Allocation ==> BS hard
// Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// 1.Each student gets at least one book.
// 2.Each book should be allocated to only one student.
// 3.Book allocation should be in a contiguous manner.

// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible, return -1

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

// To calculate total sum of array
int sumc(vector<int> arr){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

// To find number of students for holding varying pages
int count_students(vector<int> arr,int pages){     // pages is max possible pages each student is allowed to hold
    int n=arr.size();
    int stud=1;    // first student
    int p=arr[0];   // pages hold by student
    for(int i=1;i<n;i++){
        if(p+arr[i]<=pages)
         p+=arr[i];
        else 
         stud++;
         p=arr[i];
    }
    return stud;
}

// ls
int allocate_books(vector<int> arr,int m){
    int n=arr.size();

    // book allocation not possible
    if(n<m) return -1;

    int cnt=0;      // count no. of students
    for(int pages=maximum(arr);pages<=sumc(arr);pages++){
        cnt=count_students(arr,pages);
        if(cnt==m) return pages;
    }
    return -1;
}
// O(n*(sum-max+1))

// bs
int allocate_books_bs(vector<int> arr,int m){
    int n=arr.size();
    int low=maximum(arr),high=sumc(arr);
    while(low<=high){
        int mid=(low+high)/2;
        int cnt=count_students(arr,mid);
        if(cnt>m)
         // may be an answer but look for higher no. of pages
         low=mid+1;
        else
         // look for less no. of pages
         high=mid-1;
    }
    return low;
}
// O(n*log2 (sum-max+1))

int main(){
    vector<int> books={25,46,28,49,24};
    int m=4;
    // int ans=allocate_books(books,m);
    int ans=allocate_books_bs(books,m);
    cout<<"The minimum possible max number of pages which can be assigned to a student is: "<<ans;
    return 0;
}
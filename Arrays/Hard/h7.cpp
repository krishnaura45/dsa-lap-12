// Merge 2 sorted arrays without using extra space
#include<bits/stdc++.h>
using namespace std;

void mergeArr(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    vector<int> c(m+n,0);
    int i=0;  // pointer for left array
    int j=0;  // pointer for right array
    int index=0;
    while(i<n && j<m){
        if(a[i]<=b[j]){
            c[index]=a[i];
            i++;
            index++;
        }
        else{
            c[index]=b[j];
            j++;
            index++;
        }
    }
    while(i<n){
        c[index++]=a[i++];
    }
    while(j<m){
        c[index++]=b[j++];
    }

    // Fill back the elements from arr3[] to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) a[i] = c[i];
        else b[i - n] = c[i];
    }
}
// O(2(m+n)),O(m+n)

// Optimal-1 --> much good choice for interviews
void mergeArr_o1(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    int left=n-1;   // pointer for arr1
    int right=0;    // pointer for arr2
    while(left>=0 && right<m){
        if(a[left]>b[right]){
            swap(a[left],b[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
}
// O(min(n,m)) + O(nlog n) + O(mlog m) , O(1)

// Optimal-2 --> gap method
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeArr_o2(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}
// O(log2 (n+m))* O(n+m) , O(1)

int main(){
    /*
    vector<int> a1={1,3,5,7};
    vector<int> a2={0,2,6,8,9};

    // mergeArr(a1,a2);

    mergeArr_o1(a1,a2);
    for(auto it:a1) cout<<it<<" ";
    for(auto it:a2) cout<<it<<" ";
    */

    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    mergeArr_o2(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
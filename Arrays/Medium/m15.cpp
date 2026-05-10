// Leetcode 1752 - Check if array is sorted and rotated
// Brute force
class Solution {
private:
    bool check_sort(vector<int> & arr){
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]>arr[i]) return false;  
        }
        return true;
    }
public:
    bool check(vector<int>& arr) {
        int n=arr.size();
        if(check_sort(arr)) return true;
        for(int r=1;r<n;r++){
            int temp=arr[0];
            for(int i=1;i<n;i++){
                arr[i-1]=arr[i];
            }
            arr[n-1]=temp;
            if(check_sort(arr)) return true;
        }
        
        return false;
    }
};

// Optimal
class Solution {
public:
    bool check(vector<int>& arr) {
        int n=arr.size();
        int x = 0, y = 0;
    
        // Traversing array 0 to last element.
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] <=arr[i + 1])
                x++;
            else
                y++;
        }
    
        // If till now both x,y are greater than 1 then it means array is not sorted. 
        // If both any of x,y is zero then means array is not rotated.
        if(y>1) return false;
        if (y == 1) {
            // Checking for last element with first.
            if (arr[n - 1] <= arr[0])
                x++;
            else
                y++;
    
            // Checking for final result.
            if (y > 1)
                return false;
        }

        return true;
    }
};
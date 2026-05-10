// Frequency of the most frequent
// The frequency of an element is the number of times it occurs in an array.
// You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.
// Return the maximum possible frequency of an element after performing at most k operations.

// Optimal approach: sorting & Sliding window 
class Solution {
public:
    long long maxFrequency(vector<int>& arr, long long k) {
        long long n=arr.size();
        sort(arr.begin(),arr.end());
        long long start = 0, end = 0;
    
        // Stores the sum of sliding window and the maximum possible frequency of any array element
        long long sum = 0, maxf = 0;
    
        // Traverse the array
        for (end = 0; end < n; end++) {
    
            // Add the current element to the window
            sum += arr[end];
    
            // Decrease the window size
            // If it is not possible to make the array elements in the window equal
            while ((end - start + 1) * arr[end] - sum > k) {
    
                // Update the value of sum
                sum -= arr[start];
    
                // Increment the value of start
                start++;
            }
    
            // Update the maximum possible frequency
            maxf = max(maxf, end - start + 1);
        }
        return maxf;
    }
};
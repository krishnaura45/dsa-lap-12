// Reverse an Integer
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 – 1], then return 0. So we cannot multiply the number*10 and then check if the number overflows or not.

// We must check the overflow condition before multiplying by 10 by using the following logic :
// You are checking the boundary case before you do the operation. (reversed >INT_MAX ) wouldn’t work because reversed will overflow and become negative if it goes past MAX_VALUE.  Dividing MAX_VALUE by 10 lets you check the condition without overflowing INT_MAX is equal 2147483647. INT_MIN is equal  -2147483648.  The last digits are 7 and 8. This is the reason why we also  check  rem > 7 and rem < -8 conditions   
class Solution {
public:
    long long reverse(long long x) {
        long long rev=0,a=x;
        while(a!=0){
            int d=a%10;
            a=a/10;
            if(rev > INT_MAX/10 || rev == INT_MAX/10 && d > 7){
                return 0 ;
            }
            
            if(rev < INT_MIN/10 || rev == INT_MIN/10 && d < -8){
                return 0 ;
            }
            rev=rev*10+d;
        }
        return rev;
    }
};
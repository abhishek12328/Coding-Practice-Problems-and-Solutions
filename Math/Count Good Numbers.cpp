/*A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

-----------------------------------------------------------
-----------------------------------------------------------*/

class Solution {
public:
    
    int power(int x, unsigned int y){
        int res = 1; // Initialize result
        while (y > 0) {
            // If y is odd, multiply x with result
            if (y & 1)
                res = res * x;

            // y must be even now
            y = y >> 1; // y = y/2
            x = x * x; // Change x to x^2
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
       return power(5,(n+1)/2)*power(4,(n+1)/2);
    }
        
};

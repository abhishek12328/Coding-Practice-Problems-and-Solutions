/*Implement pow(x, n) % d.

In other words, given x, n and d,

find   (xn  % d)

Note that remainders on division cannot be negative. 

In other words, make sure the answer you return is non negative.

--------------------------------------------------------------------
--------------------------------------------------------------------*/


int Solution::pow(int x, int n, int d) {
    if(x==0)
    return 0;
     
    while(x<0)
    x += d;
    x = x % d;
    
    long long z = x;
    
    int ans = 1;
    
    while(n>0){
        if(n & 1)
        ans = (ans * z )%d;
        n = n >> 1;
        z = (z * z )%d;
    }
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
//better sol
class Solution {
public:
        double pow(double x,long n){
            if(n==0) return 1.0;
            if(n==1) return x;
            if(n<0) return pow(1/x,-n);
            double result = pow(x*x,n/2);
            if(n%2) result*=x;
            return result;
        }
    double myPow(double x, int n) {
        long k = n;
        return pow(x,n);
    }
};

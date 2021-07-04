/*Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

Return the maximum product you can get.

-------------------------------------------------
-------------------------------------------------*/

class Solution {
public:
    int myfunc(vector<int>& dp,int n){
        if(dp[n]!=-1)
            return dp[n];
        int maxi = INT_MIN;
        for(int i=1;i<n;i++){
            int k = max(i,myfunc(dp,i));
            int l = max(n-i,myfunc(dp,n-i));
            int temp = (k*l);
            if(temp>maxi)
                maxi = temp;
        }
        dp[n] = maxi;
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        
        return myfunc(dp,n);
    }
};

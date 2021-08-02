/*Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

-----------------------------------------------
-----------------------------------------------*/


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        
        for(int i=1;i<=n;i++){
            int temp=9;
            
            for(int j=1;j<i;j++){
                temp = temp*(10-j);
            }
            dp[i] = dp[i-1]+temp;
        }
        return dp[n];
    }
};

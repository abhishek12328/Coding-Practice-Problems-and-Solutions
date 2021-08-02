/*Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

-----------------------------------------------------------------
-----------------------------------------------------------------*/



class Solution {
public:
    int numSquares(int n) {
        
        vector<int> a;
        
        for(int i=1;i<=sqrt(n);i++){
            a.push_back(i*i);
            
        }
        vector<vector<int>> dp(a.size()+1,vector<int>(n+1,INT_MAX));
        for(int i=0;i<=a.size();i++)
            dp[i][0] = 0;
        
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]<=j)
                    dp[i][j] = min(dp[i-1][j],1+dp[i][j-a[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[a.size()][n];
    }
};

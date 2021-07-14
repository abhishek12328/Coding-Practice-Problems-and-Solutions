/*A string of '0's and '1's is monotone increasing if it consists of some number of '0's (possibly 0), followed by some number of '1's (also possibly 0.)

We are given a string s of '0's and '1's, and we may flip any '0' to a '1' or a '1' to a '0'.

Return the minimum number of flips to make s monotone increasing.

-------------------------------------------------------------------
-------------------------------------------------------------------*/

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'){
                dp[i][0] = dp[i-1][0];
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]) + 1;
            }
            if(s[i-1]=='1'){
                dp[i][0] = dp[i-1][0]+1;
                dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
            }
        }
        return min(dp[n][0],dp[n][1]);
    }
};

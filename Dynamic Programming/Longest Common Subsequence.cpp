/*Given two strings A and B. Find the longest common sequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.

-----------------------------------------
-----------------------------------------
-----------------------------------------
-----------------------------------------*/


int Solution::solve(string a, string b) {
    int m = a.size(),n = b.size();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    for(int i=0;i<n;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<m;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1] == b[j-1])
            dp[i][j] = 1+dp[i-1][j-1];
            else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}

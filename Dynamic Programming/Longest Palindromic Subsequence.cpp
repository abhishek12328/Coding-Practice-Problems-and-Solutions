/*Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.

-------------------------------------------------
-------------------------------------------------
-------------------------------------------------
-------------------------------------------------*/

int Solution::solve(string a) {
    int m = a.size(),n = a.size();
    vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    for(int i=0;i<n;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<m;i++){
        dp[i][0] = 0;
    }
    string b;
    b=a;
    reverse(b.begin(),b.end());
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

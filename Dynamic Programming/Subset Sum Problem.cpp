/*Given an integer array A of size N.

You are also given an integer B, you need to find whether their exist a subset in A whose sum equal B.

If there exist a subset then return 1 else return 0.

----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------*/


int Solution::solve(vector<int> &a, int b) {
    int n=a.size();
    vector<vector<int>> dp(n+1,vector<int>(b+1));
    sort(a.begin(),a.end());
    for(int i=0;i<=b;i++)
    dp[0][i] = 0;
    
    for(int i=0;i<=n;i++)
    dp[i][0] = 1;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b;j++){
            if(a[i-1] > j)
            dp[i][j] = dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
        }
    }
    return dp[n][b];
    
}

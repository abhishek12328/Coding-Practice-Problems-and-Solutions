/*Given an integer array A containing N integers.

You need to divide the array A into two subsets S1 and S2 such that the absolute difference between their sums is minimum.

Find and return this minimum possible absolute difference.

NOTE:

Subsets can contain elements from A in any order (not necessary to be contiguous).
Each element of A should belong to any one subset S1 or S2, not both.
It may be possible that one subset remains empty.

---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------*/

int Solution::solve(vector<int> &a) {
    int n = a.size(),sum=0;
    for(int i=0;i<n;i++)
    sum += a[i];
    int temp = (sum+1)/2 ;
    vector<vector<int>> dp(n+1,vector<int>(temp + 1));
    sort(a.begin(),a.end());
    for(int i=0;i<=temp;i++)
    dp[0][i] = 0;
    for(int i=0;i<=n;i++)
    dp[i][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=temp;j++){
            if(a[i-1] <= j)
            dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else
            dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=temp;i>=0;i--){
        if(dp[n][i] == 1)
        return abs(sum - 2*i);
    }
    return 0;
}

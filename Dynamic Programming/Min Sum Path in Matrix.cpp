/*Given a 2D integer array A of size M x N, you need to find a path from top left to bottom right which minimizes the sum of all numbers along its path.

NOTE: You can only move either down or right at any point in time.

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/

int Solution::minPathSum(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int>(A[0].size(),-1));
    int m=A.size(),n=A[0].size();
    dp[0][0] =A[0][0];
    for(int i=1;i<n;i++)
    dp[0][i] = A[0][i] + dp[0][i-1];
    for(int i=1;i<m;i++)
    dp[i][0] = A[i][0] + dp[i-1][0];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j] = A[i][j] + min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}

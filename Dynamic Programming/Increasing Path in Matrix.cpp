/*Given a 2D integer matrix A of size N x M.

From A[i][j] you can move to A[i+1][j], if A[i+1][j] > A[i][j], or can move to A[i][j+1] if A[i][j+1] > A[i][j].

The task is to find and output the longest path length if we start from (0, 0).

NOTE:

If there doesn't exist a path return -1.


-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/


int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(),m=a[0].size(),i,j;
    vector<vector<int>> dp(n,vector<int>(m));
    dp[0][0] = 1;
    for(i=1;i<m;i++){
        if(dp[0][i-1] != -1 && a[0][i-1]<a[0][i]) 
        dp[0][i] = 1+dp[0][i-1];
        else
        dp[0][i] = -1;
    }
    for(i=1;i<n;i++){
        if(dp[i-1][0] != -1 && a[i-1][0] < a[i][0])
        dp[i][0] = 1+dp[i-1][0];
        else 
        dp[i][0] = -1;
    }
    
    for(i=1;i<n;i++){
        
        for(j=1;j<m;j++){
            
            int x = INT_MIN,y=INT_MIN;
            if(a[i-1][j] < a[i][j] && dp[i-1][j] != -1)
            x = dp[i-1][j]; 
            else if(a[i][j-1] < a[i][j] && dp[i][j-1] != -1)
            y =dp[i][j-1];
            dp[i][j] = 1+max(x,y);
            if(x == INT_MIN && y==INT_MIN)
            dp[i][j] = -1;
            
        }
    }
    
    return dp[n-1][m-1];
    
}

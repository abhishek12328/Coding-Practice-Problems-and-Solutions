/*Given two integer arrays A and B of size N each which represent values and weights associated with N items respectively.

Also given an integer C which represents knapsack capacity.

Find out the maximum value subset of A such that sum of the weights of this subset is smaller than or equal to C.

NOTE:

You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------*/




int t(vector<int> &a, vector<int> &b, int c,int d, vector<vector<int>> &dp){
        if(d>=a.size())
    return 0;
    if(dp[c][d] != -1)
    return dp[c][d];
    dp[c][d] = max(((c-b[d]>=0)?(a[d]+t(a,b,c-b[d],d+1,dp)):0), t(a,b,c,d+1,dp));
    return dp[c][d];
}


int Solution::solve(vector<int> &a, vector<int> &b, int c) {

    vector<vector<int>> dp(c+1,vector<int> (a.size(),-1));
    return t(a,b,c,0,dp);
}

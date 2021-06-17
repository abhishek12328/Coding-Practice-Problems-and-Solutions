/*Given an array of non-negative integers, A, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

------------------------------------------
------------------------------------------*/



int Solution::canJump(vector<int> &a) {
    int n = a.size(),i;
    vector<int> dp(n,0);
    dp[n-1] = 1;
    for(i =n-2;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            if(i+j<n && dp[i+j] == 1)
            dp[i] = 1;
            else if(i+j>=n)
            dp[i]  = 1;
        }
    }
    return dp[0];
}

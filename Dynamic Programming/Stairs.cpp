/*You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

----------------------------------------------------
----------------------------------------------------
----------------------------------------------------
----------------------------------------------------*/


int Solution::climbStairs(int a) {
    if(a==0)
    return 0;
    if(a==1)
    return 1;
    vector<int> dp(a+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=a;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[a];
}

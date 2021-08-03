/*There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it.

For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left.
Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 109 + 7.

 ------------------------------------------------------------------------------
 ------------------------------------------------------------------------------*/


class Solution {
public:
    const static int N = 1e3 + 5, mod = 1e9 + 7;
    int dp[N][N];
    int ways(int n, int k){
        if(n == 0 and k == 0) return 1;
        if(n < 0 or k < 0) return 0;
        if(dp[n][k] == -1) {
            int visible = ways(n - 1, k - 1);
            int hidden = 1LL * ways(n - 1, k) * (n - 1) % mod;
            dp[n][k] = visible + hidden;
            dp[n][k] %= mod;
        }
        return dp[n][k];
    }
    int rearrangeSticks(int n, int k) {
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) dp[i][j] = -1;
        }
        return ways(n, k);
    }
};

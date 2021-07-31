/*Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:

perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.


-----------------------------------------------
-----------------------------------------------*/


class Solution {
public:

    int solve(vector<int> &dp,int mask,int pos,int n){
        if(dp[mask]!=-1)
            return dp[mask];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if((mask&(1<<(i-1))) && (pos%i==0 || i%pos==0)){
                mask = mask^(1<<(i-1));
                ans = ans + solve(dp,mask,pos+1,n);
                mask = mask^(1<<(i-1));
            }
                
        }
        return dp[mask] = ans;
    }
    
    int countArrangement(int n) {
        int mask = pow(2,n)-1;
        vector<int> dp(mask+1,-1);
        dp[0] = 1;
        return  solve(dp,mask,1,n);
    }
};

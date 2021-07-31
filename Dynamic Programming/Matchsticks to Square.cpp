/*You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Return true if you can make this square and false otherwise.

---------------------------------------
---------------------------------------*/


class Solution {
public:
    
    bool dfs(vector<int> &dp,vector<int> matchsticks,int mask,int k,int rem,int sum){
        if(dp[mask]!=-1)
            return dp[mask];
        int flag = 0;
        if(rem==0){
            if(dfs(dp,matchsticks,mask,k-1,sum,sum)) flag = 1;
        }
        else{
        for(int i=0;i<matchsticks.size();i++){
            if(mask&(1<<i)){
                mask = mask^(1<<i);
                if(rem-matchsticks[i] >=0)
                if(dfs(dp,matchsticks,mask,k,rem-matchsticks[i],sum)) flag = 1;
                mask = mask^(1<<i);
            }
        }
        }
        return dp[mask] = flag;
    }
    bool makesquare(vector<int>& matchsticks) {
        int mask = pow(2,matchsticks.size())-1;
        vector<int> dp(mask+1,-1);
        dp[0] = 1;
        int temp=0;
        for(int i=0;i<matchsticks.size();i++)
            temp+= matchsticks[i];
        if(temp%4 != 0)
            return false;
        return dfs(dp,matchsticks,mask,4,temp/4,temp/4);
            
    }
};

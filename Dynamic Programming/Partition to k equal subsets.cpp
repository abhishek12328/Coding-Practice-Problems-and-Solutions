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
    
    bool canPartitionKSubsets(vector<int>& matchsticks, int k) {
                int mask = pow(2,matchsticks.size())-1;
        vector<int> dp(mask+1,-1);
        dp[0] = 1;
        int temp=0;
        for(int i=0;i<matchsticks.size();i++)
            temp+= matchsticks[i];
        if(temp%k != 0)
            return false;
        return dfs(dp,matchsticks,mask,k,temp/k,temp/k);
    }
};


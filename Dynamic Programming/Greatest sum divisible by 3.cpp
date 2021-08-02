/*Given an array nums of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

-----------------------------------------------
-----------------------------------------------*/


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size(),ans = 0;
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][nums[0]%3] = nums[0];  
        for(int i=1;i<n;i++){
            if(nums[i]%3==0){
                
                dp[i][0]  = (dp[i-1][0]%3==0)?(max(dp[i-1][0]+nums[i],dp[i-1][0])):dp[i-1][0] ;
                dp[i][1] = (dp[i-1][1]%3==1)?(max(dp[i-1][1]+ nums[i],dp[i-1][1])):dp[i-1][1] ;
                dp[i][2] = (dp[i-1][2]%3==2)?(max(dp[i-1][2]+ nums[i],dp[i-1][2])):dp[i-1][2] ;
            }
            if(nums[i]%3==1){
                dp[i][0]  = (dp[i-1][2]%3==2)?(max(dp[i-1][2]+ nums[i],dp[i-1][0])):dp[i-1][0];
                dp[i][1] = (dp[i-1][0]%3==0)?(max(dp[i-1][0]+ nums[i],dp[i-1][1])):dp[i-1][1] ;
                dp[i][2] = (dp[i-1][1]%3==1)?(max(dp[i-1][1]+ nums[i],dp[i-1][2])):dp[i-1][2] ;
            }
            if(nums[i]%3==2){
                dp[i][0]  = (dp[i-1][1]%3==1)?(max(dp[i-1][1]+ nums[i],dp[i-1][0])):dp[i-1][0] ;
                dp[i][1] = (dp[i-1][2]%3==2)?(max(dp[i-1][2]+ nums[i],dp[i-1][1])):dp[i-1][1] ;
                dp[i][2] = (dp[i-1][0]%3==0)?(max(dp[i-1][0]+ nums[i],dp[i-1][2])):dp[i-1][2] ;
            }
            
            
        }
        return dp[n-1][0];
         
    }
};

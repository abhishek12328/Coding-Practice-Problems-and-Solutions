/*Given an array nums of integers, return the length of the longest arithmetic subsequence in nums.

Recall that a subsequence of an array nums is a list nums[i1], nums[i2], ..., nums[ik] with 0 <= i1 < i2 < ... < ik <= nums.length - 1, and that a sequence seq is arithmetic if seq[i+1] - seq[i] are all the same value (for 0 <= i < seq.length - 1).

 ---------------------------------------------------------------------
 ---------------------------------------------------------------------*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(600,vector<int>(1501,0));

        int ans =0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<dp[0].size();j++)
             dp[nums[i-1]][j] = (dp[nums[i-1]][j]==0)?1:dp[nums[i-1]][j];
            for(int j=-500;j<=500;j++){
                
                if(0<=nums[i]+j && nums[i]+j<=500){
                dp[nums[i]][500+j] = 1+ dp[nums[i]+j][500+j];
                if(ans < dp[nums[i]][500+j]){
                    ans = dp[nums[i]][500+j];

                }
                    
                    }
            }
        }
        return ans;
    }
};

/*We partition a row of numbers nums into at most k adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in nums, and that scores are not necessarily integers.
---------------------------------------------------------
---------------------------------------------------------*/

class Solution {
public:
double helper(vector<vector<double>>&dp ,vector<int> &nums,int k,int pos){
if(pos>=nums.size())
return 0;
if(k==0)
return INT_MIN;
if(dp[pos][k]!=-1)
return dp[pos][k];
double sum = 0;
double ans = 0;
for(int i=pos;i<nums.size();i++){
sum += nums[i];
ans = max(ans,sum/(i-pos+1)+helper(dp,nums,k-1,i+1));
}
return dp[pos][k] = ans;
}
double largestSumOfAverages(vector<int>& nums, int k) {
    vector<vector<double>> dp(nums.size(), vector<double> (k+1,-1));
return helper(dp,nums,k,0);
}
};

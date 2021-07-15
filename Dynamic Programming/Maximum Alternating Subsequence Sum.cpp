/*Maximum Alternating Subsequence Sum
User Accepted:1594
User Tried:2187
Total Accepted:1670
Total Submissions:3725
Difficulty:Medium
The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

------------------------------------------------------------------
------------------------------------------------------------------*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n,vector<long long>(4,0));
        dp[0][0] = nums[0];
        long long m = nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]  = max(dp[i-1][1],dp[i-1][3]) + nums[i];
            m =  max(m,dp[i][0]);
            dp[i][1]  = max(dp[i-1][0],dp[i-1][2]) - nums[i];
            m =  max(m,dp[i][1]);
            dp[i][2] = max(dp[i-1][0],dp[i-1][2]);
            m =  max(m,dp[i][1]);
            dp[i][3] = max(dp[i-1][1],dp[i-1][3]);
            m =  max(m,dp[i][1]);
        }
        return m;
    }
};

/*Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

*/


class Solution {
public:
    int jump(vector<int>& a) {
        int n = a.size(),i;
        vector<int> dp(n,INT_MAX);
        dp[n-1] = 0; 
        for(i=n-2;i>=0;i--){
            for(int j=1;j<=a[i];j++){
                if(i+j>=n){
                    dp[i] = 1;
                    break;
                }
                else if(dp[i+j] != INT_MAX){
                    
                    dp[i] = 1 + min(dp[i]-1,dp[i+j]);
                    
                }
            }
        }
        return dp[0];
    }
};

        
    

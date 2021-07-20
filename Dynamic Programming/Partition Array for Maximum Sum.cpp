/*Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.


---------------------------------------------------------------------
---------------------------------------------------------------------*/



class Solution {
public:
    int helper(vector<int>&arr,vector<int>&dp,int i,int n,int k){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        int mx_ele=INT_MIN;
        for(int j=i;j<min(i+k,n);j++){
            mx_ele=max(mx_ele,arr[j]);
            int sum=((j-i+1)*mx_ele)+helper(arr,dp,j+1,n,k);
            ans=max(ans,sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return helper(arr,dp,0,arr.size(),k);
    }
};

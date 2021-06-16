/*Find the longest increasing subsequence of a given array of integers, A.

In other words, find a subsequence of array in which the subsequence’s elements are in strictly increasing order, and in which the subsequence is as long as possible.
This subsequence is not necessarily contiguous, or unique.
In this case, we only care about the length of the longest increasing subsequence.


------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------*/


int Solution::lis(const vector<int> &a) {
    int n=a.size(),i,j,ans = 0;
    vector<int> dp(n,1);
    
    for(i=n-1;i>=0;i--){
        int max = 0;
        for(j=i+1;j<n;j++){
            if(a[i]<a[j] && max<dp[j]){
            
                max = dp[j];
            }
        }
        dp[i] = max+1;
        if(ans<dp[i])
        ans = dp[i];
    }
    return ans;
}

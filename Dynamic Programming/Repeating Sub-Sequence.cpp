/*Given a string A, find length of the longest repeating sub-sequence such that the two subsequence don’t have same string character at same position,

i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

NOTE: Sub-sequence length should be greater than or equal to 2.

-------------------------------------------
-------------------------------------------*/

int Solution::anytwo(string a) {
    int n=a.size(),i,j;
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    string b = a;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j){

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            if(dp[i][j] >= 2) 
            return 1;
        }
    }
    return 0;

}

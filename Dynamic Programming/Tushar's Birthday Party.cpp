/*As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.

 Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

NOTE:

Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.

--------------------------------------------------
--------------------------------------------------*/


int Solution::solve(const vector<int> &a, const vector<int> &B, const vector<int> &C) {
    int l = a.size(),m = B.size(),i,j,k,ans=0,maximum = 0;
    vector<int> b = B,c =C;

    for(k=0;k<l;k++){
        maximum = max(maximum, a[k]);
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            if(b[i]>b[j]){
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                temp = c[i];
                c[i] =c[j];
                c[j] = temp;
            }
        }
    }
        vector<vector<int>> dp(m+1,vector<int>(maximum+1,INT_MAX));
        for(i=0;i<=m;i++)
        dp[i][0] = 0;
        for(i=1;i<=m;i++){
            for(j=1;j<=maximum;j++){
                if(j<b[i-1])
                dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = min(c[i-1] + dp[i][j-b[i-1]] , dp[i-1][j]);
                }
            }
        }

        for(k=0;k<l;k++){
        ans = ans + dp[m][a[k]];
        }
    
    return ans;
}

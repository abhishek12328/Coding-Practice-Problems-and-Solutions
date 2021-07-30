/*Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


--------------------------------
--------------------------------*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size()));
        
        int ans=INT_MAX;
        for(int i=0;i<matrix[0].size();i++){
            dp[0][i] = matrix[0][i]; 
            if(matrix.size()==1)
            ans = min(ans,dp[0][i]);
        }
        int m = matrix.size(),n=matrix[0].size();
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j==0){
                    if(j+1<n)
                    dp[i][j] = matrix[i][j] + (min(dp[i-1][j],dp[i-1][j+1]));
                    else
                    dp[i][j] = matrix[i][j] + (min(dp[i-1][j],dp[i-1][j+1]));

                }
                else if(j==n-1){
                    if(j-1>=0)
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                    else
                    dp[i][j] = matrix[i][j] + 0;
                        
                }
                else{
                    dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                }
                if(i==m-1)
                ans = min(ans,dp[i][j]);
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
    }
};

/*Given a 2D grid of 0s and 1s, return the number of elements in the largest square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't exist in the grid.

 -------------------------------------------------------------
 -------------------------------------------------------------*/


class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>> r(101,vector<int>(101,0));
        vector<vector<int>> c(101,vector<int>(101,0));
        int ans=0;
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                if(grid[i-1][j-1] == 1){
                    r[i][j] = 1+r[i][j-1];
                    c[i][j] = 1+c[i-1][j];
                        for(int k=0;k<min(r[i][j],c[i][j]);k++){
                            if(r[i-k][j] >= k+1 && c[i][j-k]>= k+1 )
                                ans = max(ans,(k+1)*(k+1));
                        
                    }
                }
            }
        }
        return ans;
    }
};

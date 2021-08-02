/*On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly k moves or has moved off the chessboard.

Return the probability that the knight remains on the board after it has stopped moving.

 ------------------------------------------------------
 ------------------------------------------------------*/

class Solution {
public:
    
    double solve(vector<vector<vector<double>>> &dp,int row,int col,int k,int n){
        if(row<0 || col>=n || col<0 || row>=n){
            return 0;
        }
        if(k==0)
            return 1;
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        vector<int> r = {-1,-2,-2,-1,1,2,2,1};
        vector<int> c = {-2,-1,1,2,-2,-1,1,2};
        double ans=0;
        for(int i=0;i<8;i++){
            ans += solve(dp,row+r[i],col+c[i],k-1,n);
        }
        return dp[row][col][k] = ans;
        
        
    }
    
    double knightProbability(int n, int k, int row, int column) {
        int count=0;
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double ans = solve(dp,row,column,k,n);
        double div = pow(8,k);
        return ans/div;
    }
};

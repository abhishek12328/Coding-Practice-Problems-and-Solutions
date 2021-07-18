/*You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

-------------------------------------------------------------------------------
-------------------------------------------------------------------------------*/


class Solution {
public:
    
    bool myfunc(int i,int j,vector<vector<int>>& visited, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int flag){
        visited[i][j] = 1;
        vector<int> row = {0,-1,1,0};
        int flag1 = 0,flag2 = 0;
        vector<int> col = {-1,0,0,1};
        int m = grid1.size(), n = grid1[0].size();
        if(flag == 1){
        for(int k=0;k<4;k++){
            if(i+row[k]>=0 && i+row[k]<m && j+col[k]>=0 && j+col[k]<n && !visited[i+row[k]][j+col[k]] && grid2[i+row[k]][j+col[k]]){
                if(grid1[i+row[k]][j+col[k]]){
                if(!myfunc(i+row[k],j+col[k],visited,grid1,grid2,1)){
                    flag2 = 1;
                }
                }
                else{
                  myfunc(i+row[k],j+col[k],visited,grid1,grid2,0);
                    flag1 = 1;
                }
            }
            
        }
            if(flag1 == 0 && flag2 ==0)
                return true;
            else
                return false;
        }
        else{
          for(int k=0;k<4;k++){
            if(i+row[k]>=0 && i+row[k]<m && j+col[k]>=0 && j+col[k]<n && !visited[i+row[k]][j+col[k]] && grid2[i+row[k]][j+col[k]])
                myfunc(i+row[k],j+col[k],visited,grid1,grid2,0);
        }  
            return false;
        }
        
        return true;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid1[i][j] && grid2[i][j]){
                    if(myfunc(i,j,visited,grid1,grid2,1))
                        count++;
                }
            }
        }
        return count;
    }
};

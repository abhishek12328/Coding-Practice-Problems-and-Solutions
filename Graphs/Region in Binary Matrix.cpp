/*Given a binary matrix A of size N x M.

Cells which contain 1 are called filled cell and cell that contain 0 are called empty cell.

Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally.

If one or more filled cells are also connected, they form a region. Find the length of the largest region.


----------------------------------------------------
-----------------------------------------------------*/


int dfs(vector<vector<int>> &a,int i ,int j,vector<vector<int>>& visited){
    vector<int> row = {-1,-1,-1,0,0,1,1,1};
    vector<int> col = {-1,0,1,-1,1,-1,0,1};
    visited[i][j] = true;
    int max = 0;
    for(int k=0;k<8;k++){
        if(i+row[k]>=0 && i+row[k]<a.size() && j+col[k]>=0 && j+col[k]<a[0].size() && !visited[i+row[k]][j+col[k]] && a[i+row[k]][j+col[k]]){
            int temp = dfs(a,i+row[k],j+col[k],visited);
            
            max += temp;
        }
    }
    return max + 1;
}

int Solution::solve(vector<vector<int> > &a) {
    int m = a.size(),n = a[0].size();
    vector<vector<int>> visited(a.size(),vector<int>(a[0].size(),false));
    int max = INT_MIN;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            if(!visited[i][j] && a[i][j]){
                int temp = dfs(a,i,j,visited);
                if(max < temp)
                max = temp;
            }
        }
    }
    return max;
}

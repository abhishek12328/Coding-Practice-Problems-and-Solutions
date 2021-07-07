/*There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.


------------------------------------------------------
------------------------------------------------------*/

string dfs(vector<vector<int>>& adj, vector<vector<int>> &visited ,int x, int y){
    

    if( x == adj.size()-1 && y == adj[0].size()-1)
    return "YES";
    
    visited[x][y] = true;
    vector<int> row = {-1,-1,-1,0,0,1,1,1};
    vector<int> col = {-1,0,1,-1,1,-1,0,1};
    
    for(int i=0;i<8;i++){
        
        if(x+row[i]>=0 && x+row[i]<adj.size() && y+col[i]>=0 && y+col[i]<adj[0].size() && !visited[x+row[i]][y+col[i]] && adj[x+row[i]][y+col[i]]){
            if(dfs(adj,visited,x+row[i],y+col[i]) == "YES") return "YES";
        }
    }
    return "NO";
}


string Solution::solve(int x, int y, int n, int r, vector<int> &e, vector<int> &f) {
    vector<vector<int>> adj(x+1,vector<int>(y+1,1));
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k=0;k<n;k++){
                if((i-e[k])*(i-e[k])+(j-f[k])*(j-f[k])-(r)*(r)<=0){
                adj[i][j] = 0;
                break;
                }
            }
        }
    }
    vector<vector<int>> visited(x+1,vector<int> (y+1,false));
    return dfs(adj,visited,0,0);
}

/*Given N x M character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

-----------------------------------------------------------------
-----------------------------------------------------------------*/


void dfs(vector<string>& a,vector<vector<int>> & visited,int i,int j){
    visited[i][j] = true;
    vector<int> row = {0,-1,1,0};
    vector<int> col = {-1,0,0,1};
    for(int k=0;k<4;k++){
        if(i+row[k]>=0 && i+row[k]<a.size() && j+col[k]>=0 && j+col[k]<a[0].size() && !visited[i+row[k]][j+col[k]] && a[i+row[k]][j+col[k]] == 'X')
        dfs(a,visited,i+row[k],j+col[k]);
    }
    return;
}

int Solution::black(vector<string> &a) {
    // vector<vector<int>> adj(a.size(),a[0].size());
    
    // for(int i=0;i<a.size();i++){
    //     for(int j=0;j<a[0].size();j++){
    //         if(a[i][j] == )
    //     }
        
    // }
    int count=0;
    vector<vector<int>> visited(a.size(),vector<int>(a[0].size(),false));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            if(!visited[i][j] && a[i][j] == 'X'){
            dfs(a,visited,i,j);
            count++;
            }
        }
    }
    return count;
    
}

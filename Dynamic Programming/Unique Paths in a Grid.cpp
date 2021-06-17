/*Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

----------------------------------------------
----------------------------------------------
----------------------------------------------
----------------------------------------------*/


int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
    int m = a.size(),n=a[0].size();
    vector<vector<int>> v(m,vector<int>(n,0));
    v[0][0] = 1-a[0][0];
    for(int i=1;i<m;i++){
        if(a[i][0] != 1)
        v[i][0] = v[i-1][0];
    }
    for(int i=1;i<n;i++){
        if(a[0][i] != 1)
        v[0][i] = v[0][i-1];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(a[i][j] != 1)
            v[i][j] = v[i][j-1] + v[i-1][j];
        }
    }
    return v[m-1][n-1];
}

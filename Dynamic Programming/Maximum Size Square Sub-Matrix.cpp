/*Given a 2D binary matrix A of size  N x M  find the area of maximum size square sub-matrix with all 1's.

------------------------------------------------
------------------------------------------------*/

int Solution::solve(vector<vector<int> > &a){
    int n=a.size(),m=a[0].size(),i,j,max = 0;
    vector<vector<int>> r(n,vector<int>(m,0));
    r[0][0] = a[0][0];
    for(i=1;i<n;i++){
        if(a[i][0] == 1){
        r[i][0] = 1;
        max = 1;
        }
    }
    for(i=1;i<m;i++){
        if(a[0][i] == 1){
        r[0][i] = 1;
        max = 1;
        }
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(a[i][j] == 1){
                r[i][j] = 1+ min(r[i-1][j-1],min(r[i-1][j],r[i][j-1]));
                if(max < r[i][j]*r[i][j])
                max = r[i][j]*r[i][j];
            }
        }
    }
    return max;
    
}

/*Given a 2D integer array A of size  N * N  representing a triangle of numbers.

Find the maximum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

NOTE:

Adjacent cells to cell (i,j) are only (i+1,j) and (i+1,j+1)
Row i contains i integer and n-i zeroes for all i in [1,n] where zeroes represents empty cells.

-----------------------------------------------------
-----------------------------------------------------
-----------------------------------------------------
-----------------------------------------------------*/

int Solution::solve(vector<vector<int> > &a) {
    int n=a[0].size(),maxi = a[0][0];
    vector<vector<int>> v(n,vector<int>(n,0));
    v[0][0] = a[0][0];
    for(int i=1;i<n;i++)
    v[i][0] = a[i][0] + v[i-1][0];
    for(int i=1;i<n;i++){
    for(int j=1;j<=i;j++){
    v[i][j] = a[i][j] + max(v[i-1][j] , v[i-1][j-1]);
    if(v[i][j] > maxi)
    maxi = v[i][j];
    }
    }
    return maxi;
}

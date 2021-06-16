/*There are a row of N houses, each house can be painted with one of the three colors: red, blue or green.

The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a N x 3 cost matrix A.

For example, A[0][0] is the cost of painting house 0 with color red; A[1][2] is the cost of painting house 1 with color green, and so on.

Find the minimum total cost to paint all houses.

-----------------------------------------------------
-----------------------------------------------------
-----------------------------------------------------
-----------------------------------------------------*/

int Solution::solve(vector<vector<int> > &a) {
    int n =a.size(),i;
    vector<vector<int>> v(n,vector<int>(3));
    v[0] = a[0];
    
    for(i=1;i<n;i++){
        v[i][0] = a[i][0] + min(v[i-1][1],v[i-1][2]);
        v[i][1] = a[i][1] + min(v[i-1][0],v[i-1][2]);
        v[i][2] = a[i][2] + min(v[i-1][1],v[i-1][0]);
    }
    return min(v[n-1][0],min(v[n-1][1],v[n-1][2]));
}

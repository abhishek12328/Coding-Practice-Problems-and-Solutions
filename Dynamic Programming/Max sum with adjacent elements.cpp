/*Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers

is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.

------------------------------------------------
------------------------------------------------*/

int Solution::adjacent(vector<vector<int> > &a) {
    // 1 taken
    vector<vector<int>> t(a[0].size(),vector<int>(2,0));
    vector<vector<int>> b(a[0].size(),vector<int>(2,0));
    t[0][0] = 0;
    t[0][1] = a[0][0];
    b[0][0] = 0;
    b[0][1] = a[1][0];

    for(int i=1;i<a[0].size();i++){
        t[i][0] = max(t[i-1][0],max(b[i-1][0],max(t[i-1][1],b[i-1][1]))); 
        t[i][1] = a[0][i] + max(t[i-1][0],b[i-1][0]);
        b[i][0] = max(t[i-1][0],max(t[i-1][1],max(b[i-1][0],b[i-1][1])));
        b[i][1] = a[1][i] + max(t[i-1][0],b[i-1][0]);
    }
    int n = a[0].size();
    return max(b[n-1][0],max(b[n-1][1],max(t[n-1][0],t[n-1][1])));
}

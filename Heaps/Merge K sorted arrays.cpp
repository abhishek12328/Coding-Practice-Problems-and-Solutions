/*You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.

You need to merge them into a single array and return it.

----------------------------------------------------------------
----------------------------------------------------------------*/


vector<int> Solution::solve(vector<vector<int> > &a) {
    int i,n = a.size(),m=a[0].size();
    priority_queue<int,vector<int>,greater<int>> q;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            q.push(a[i][j]);
        }
    }
    vector<int> v;
    while(!q.empty()){
        v.push_back(q.top());
        q.pop();
    }
    return v;
}

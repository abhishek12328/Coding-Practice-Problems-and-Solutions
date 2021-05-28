vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>> ans(A);
    if(A==0)
    return ans;
    ans[0].push_back(1);
    for(int i=1;i<A;i++){
        for(int j=0;j<i;j++){
            if(j==0)
            ans[i].push_back(1);
            else
            ans[i].push_back(ans[i-1][j]+ans[i-1][j-1]);
        }
        ans[i].push_back(1);
    }
    return ans;
}

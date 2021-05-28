vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    int i,j,k,temp,n=a.size();
    vector<vector<int>> ans(2*n-1);
    for(k=0;k<n;k++){
        for(i=0;i<=k;i++){
            j=k-i;
            ans[k].push_back(a[i][j]);
        }
    }
    for(k=0;k<n-1;k++){
        for(i=n-k-1;i<=n-1;i++){
            j= n+(n-i-k-2);
            ans[2*n-2-k].push_back(a[i][j]);
        }
    }
    return ans;
}

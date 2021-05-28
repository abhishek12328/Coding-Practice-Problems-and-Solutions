vector<int> Solution::wave(vector<int> &a) {
    int i,n = a.size();
    sort(a.begin(),a.end());
    vector<int> ans(n);
    for(i=0;i<n;i++){
        if(i%2==0 && i+1<n)
        ans[i+1] = a[i];
        if(i%2==1)
        ans[i-1] = a[i];
        if(i%2==0 && i+1==n)
        ans[i] = a[i];
        
        
    }
    return ans;
}

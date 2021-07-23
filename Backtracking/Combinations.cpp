/*Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.


-------------------------------------------------------------
-------------------------------------------------------------*/




void solve(int a ,int b, int start, int done,vector<vector<int>> & ans,vector<int> v){
    if(done == b)
    ans.push_back(v);
    
    for(int i=start;i<=a;i++){
        v.push_back(i);
        solve(a,b,i+1,done+1,ans,v);
        v.pop_back();
    }
    
}

vector<vector<int> > Solution::combine(int a, int b){
    vector<vector<int>> ans;
    solve(a,b,1,0,ans,{});
    return ans;
}

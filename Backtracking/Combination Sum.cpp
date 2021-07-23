/*Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.

----------------------------------------------------------------
----------------------------------------------------------------*/


vector<vector<int>> solve(vector<int> a,vector<int> v,int sum,int tar,int ind){
    vector<vector<int>> ans,fans;
    if(sum>tar)
    return ans;
    if(sum==tar)
    return {v};
    for(int i=ind;i<a.size();i++){
        v.push_back(a[i]);
        if(sum+a[i]<=tar)
        ans = solve(a,v,sum+a[i],tar,i);
        else
        ans = {};
        for(int j=0;j<ans.size();j++){
            fans.push_back(ans[j]);
        }
        v.pop_back();
    }
    return fans;
}


vector<vector<int>> Solution::combinationSum(vector<int> &a, int b) {
    vector<int> v,v1;
    
    set<int> s;
    for(int i=0;i<a.size();i++){
        s.insert(a[i]);
    }
    for(auto i=s.begin();i!=s.end();i++){
    v1.push_back(*i);
    }
    sort(v1.begin(),v1.end());
    return solve(v1,v,0,b,0);
}

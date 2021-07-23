/*Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.

------------------------------------------------------
------------------------------------------------------*/


vector<vector<int>> solve(vector<int> a,int i){
    int n = a.size();
    vector<vector<int>> v2;
    if (i==n)
    return v2;
    vector<vector<int>> v1;
    v1 = solve(a,i+1);
    vector<vector<int>> v;
    v.push_back({a[i]});
    for(int j=0;j<v1.size();j++){
        v.push_back({a[i]});
       v[j+1].insert(v[j+1].end(), v1[j].begin(), v1[j].end());
    }
    for(int j=0;j<v1.size();j++){
        v.push_back(v1[j]);
    }
    return v;
}


vector<vector<int> > Solution::subsets(vector<int> &a) {
    int n = a.size();
    sort(a.begin(),a.end());
    vector<vector<int>> v,v1;
    vector<int> t;
    v.push_back(t);
    v1 = solve(a,0);
    
    for(int j=0;j<v1.size();j++){
        v.push_back(v1[j]);
    }
    return v;
}

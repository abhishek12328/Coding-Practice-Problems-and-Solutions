/*Given a collection of numbers, return all possible permutations.

-------------------------------------------------------------
-------------------------------------------------------------*/


vector<vector<int>> Solution::permute(vector<int> &a) {
    
    vector<vector<int>> ans;
    if(a.size()==1)
    return {a};
    for(int i=0;i<a.size();i++){
        vector<int> temp = a;
        temp.erase(temp.begin()+i);
        vector<vector<int>> tans = permute(temp);
        
        for(int j=0;j<tans.size();j++){
            vector<int> ele = {a[i]};
        ele.insert(ele.end(),tans[j].begin(),tans[j].end());
        ans.push_back(ele);
        }
    }
    return ans;
}

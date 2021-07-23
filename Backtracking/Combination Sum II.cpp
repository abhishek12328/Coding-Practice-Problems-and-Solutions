/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.


--------------------------------------------------------------------------
--------------------------------------------------------------------------*/



void solve(vector<int> a,vector<int> v,int sum,int rem,int tar,int ind,vector<vector<int>>& ans){
    
    
    if(sum==tar)
    ans.push_back(v);
    
    for(int i=ind;i<a.size();i++){
        rem = rem - a[i];
        if((i>ind && a[i-1]!=a[i])||i==ind){
        v.push_back(a[i]);
        if((sum+a[i])+rem<tar)
        break;
        solve(a,v,sum+a[i],rem,tar,i+1,ans);
        v.pop_back();
        }
    }
   
}



vector<vector<int> > Solution::combinationSum(vector<int> &a, int b) {
    sort(a.begin(),a.end());
    vector<vector<int>> ans;
    vector<int> z;
    int tot=0;
    for(int i=0;i<a.size();i++)
    tot+=a[i];
    solve(a,z,0,tot,b,0,ans);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}






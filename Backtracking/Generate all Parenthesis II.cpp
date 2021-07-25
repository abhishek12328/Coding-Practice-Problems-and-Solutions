/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"


-----------------------------------------------------------------
------------------------------------------------------------------*/


void solve(vector<string>& ans,string s,int remopen, int remclose){
    if(remopen == 0 && remclose == 0)
    ans.push_back(s);
    if(remopen!=0)
    solve(ans,s+"(",remopen-1,remclose+1);
    if(remclose!=0)
    solve(ans,s+")",remopen,remclose-1);
    
}

vector<string> Solution::generateParenthesis(int a) {
    vector<string> ans;
    string s;
    solve(ans, "", a,0);
    return ans;
}

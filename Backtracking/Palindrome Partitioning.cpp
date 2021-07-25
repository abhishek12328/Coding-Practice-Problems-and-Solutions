/*Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))



--------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------*/


bool ispalindrome(string a){
    for(int i=0;i<a.size();i++){
        if(a[i]!=a[a.size()-1-i])
        return false;
    }
    return true;
}

void solve(vector<vector<string>> & ans,vector<string> v,int start,string a){
    if(start==a.size())
    ans.push_back(v);
    
    for(int i=start;i<a.size();i++){
        if(ispalindrome(a.substr(start,i-start+1))){
            v.push_back(a.substr(start,i-start+1));
            solve(ans,v,i+1,a);
            v.pop_back();
        }
    }
}


vector<vector<string> > Solution::partition(string a){
    vector<vector<string>> ans;
    vector<string> v;
    solve(ans,v,0,a);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

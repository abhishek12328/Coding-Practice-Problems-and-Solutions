/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.


------------------------------------------------------------------------
------------------------------------------------------------------------*/


vector<string> Solution::letterCombinations(string a) {
    map<char,vector<string>> m;
    m['1'] = {"1"};
    m['2'] = {"a","b","c"};
    m['3'] = {"d","e","f"};
    m['4'] = {"g","h","i"};
    m['5'] = {"j","k","l"};
    m['6'] = {"m","n","o"};
    m['7'] = {"p","q","r","s"};
    m['8'] = {"t","u","v"};
    m['9'] = {"w","x","y","z"};
    m['0'] = {"0"};
    if(a.size()==1)
    return m[a[0]];
    vector<string> v,ans;
    v = letterCombinations(a.substr(1,a.size()-1));
    for(int j=0;j<m[a[0]].size();j++){
        
    for(int i=0;i<v.size();i++){
        string s = m[a[0]][j];
        s = s+v[i];
        ans.push_back(s);
    }
    }
    return ans;
}

/*Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.

---------------------------------------
---------------------------------------
---------------------------------------
---------------------------------------*/

string Solution::solve(string a) {
    vector<string> v;
    string s;
    int flag = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]==' '){
            flag = 1;
            if(s.size())
            v.push_back(s);
            s = "";
        }
        else{
        s.push_back(a[i]);
        flag = 0;
        }
    }
    if(flag == 0)
    v.push_back(s);
    s="";
    for(int i=v.size()-1;i>=0;i--){
       s = s+v[i];
       s = s+ " ";
    }
    return s.substr(0,s.size()-1);
}

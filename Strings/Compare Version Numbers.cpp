/*Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/


int Solution::compareVersion(string a, string b) {
    int m = a.size(),i=0,n=b.size();
    vector<string> f,s;
    string temp;
    while(i<m){
        while(i<m && a[i]=='0') i++;
        temp ="";
        while(i<m && '0'<=a[i] && a[i]<='9'){
            temp.push_back(a[i]);
            i++;
        }
        if(temp!="")
        f.push_back(temp);
        else
        f.push_back("0");
        if(i<m && a[i]!='.')
        break;
        i++;
    }
    i=0;
    while(i<n){
        while(i<n && b[i]=='0') i++;
        temp ="";
        while(i<n && '0'<=b[i] && b[i]<='9'){
            temp.push_back(b[i]);
            i++;
        }
        if(temp!="")
        s.push_back(temp);
        else
        s.push_back("0");
        if(i<n && b[i]!='.')
        break;
        i++;
    }
    int j;
    for(i=0,j=0;i<f.size() && j<s.size();i++,j++){
        if(f[i].size()==s[j].size()){
        if(f[i]<s[j])
        return -1;
        else if(f[i]>s[j])
        return 1;
        }
        else if(f[i].size()>s[j].size()) return 1;
        else if(f[i].size()<s[j].size()) return -1;
    }
    while(i<f.size() && f[i]=="0") i++;
    if(i < f.size()) return 1; 
   
    while(j<s.size() && s[j]=="0") i++;
    if(j < s.size() ) return -1;
    return 0;
}

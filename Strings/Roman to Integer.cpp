/*Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

-----------------------------------
-----------------------------------
-----------------------------------
-----------------------------------*/

int Solution::romanToInt(string a) {
    map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int ans=0,i,n=a.size();
    for(i=0;i<n-1;i++){
        if(m[a[i]]<m[a[i+1]])
        ans = ans - m[a[i]];
        else
        ans += m[a[i]];
    }
    ans = ans+m[a[i]];
    return ans;
}

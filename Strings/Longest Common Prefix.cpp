/*Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

----------------------------------------------
----------------------------------------------
----------------------------------------------
----------------------------------------------*/

int prefix(string a,string b){
    int m = a.size(),n=b.size();
    if(a[0]!=b[0])
    return 0;
    if(m<n)
    n = m;
    for(int i=0;i<n;i++)
    if( a.substr(0,i)!= b.substr(0,i))
    return i-1;
    return n;
}

string Solution::longestCommonPrefix(vector<string> &a) {
    int n=a.size(),min =INT_MAX;
    for(int i=0;i<n-1;i++){
        int k = prefix(a[i],a[i+1]);
        if(k<min)
        min = k;
    }
    if(n!=0 && min!=0)
    return a[0].substr(0,min);
    else
    return "";
}

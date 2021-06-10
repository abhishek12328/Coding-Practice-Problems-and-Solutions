/*Given a string A consisting of lowercase characters.

You have to find the number of substrings in A which starts with vowel and end with consonants or vice-versa.

Return the count of substring modulo 109 + 7.
----------------------------
----------------------------
----------------------------
----------------------------*/



int Solution::solve(string a) {
    int count=0,i,n=a.size();
    vector<int> v(n),c(n),d(n);
    v[0] = 0;
    c[0] = 0;
    for(i=0;i<n;i++){
        if(i!=0){
            if(a[i-1] == 'a'||a[i-1] == 'e'||a[i-1] == 'i'||a[i-1] == 'o'||a[i-1] == 'u'){
            v[i] = v[i-1] + 1;
            c[i] = c[i-1];
            }
            else{
            c[i] = c[i-1] + 1;
            v[i] = v[i-1];
            }
        }
        if(a[i] == 'a'||a[i] == 'e'||a[i] == 'i'||a[i] == 'o'||a[i] == 'u')
        d[i] = 1;
        else
        d[i] = 0;
    }
    for(i=0;i<n;i++){
        if(d[i] == 0)
        count += v[i];
        else
        count+= c[i];
        count = count%1000000007;
    }
    return count;
}

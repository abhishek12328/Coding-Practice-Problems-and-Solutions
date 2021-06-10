/*You are given a string S, and you have to find all the amazing substrings of S.

Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).

-----------------------------------
-----------------------------------
-----------------------------------
-----------------------------------*/


int Solution::solve(string a) {
    int n = a.size(),i,count =0;
    for(i=0;i<n;i++){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='O'||a[i]=='U'||a[i]=='I'){
            count+=n-i;
            count = count%10003;
        }
    }
    return count;
}

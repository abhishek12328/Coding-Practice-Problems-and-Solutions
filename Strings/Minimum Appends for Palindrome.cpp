/*Given a string A consisting of lowercase characters.

We need to tell minimum characters to be appended (insertion at end) to make the string A a palindrome.

-------------------------------------
-------------------------------------
-------------------------------------
-------------------------------------*/






int Solution::solve(string a) {
    
    int n = a.size(),i,j,ans=0;
    if(n==0)
    return 0;
    for(i=0,j=n-1;i<n && j>=0;i++,j--){
        if(a[i]!=a[j]){
            j=n;
            ans = i+1;
        }
    }
    if(ans == n)
    ans = n-1;
    return ans;
}

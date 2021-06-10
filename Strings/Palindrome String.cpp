/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------*/


int Solution::isPalindrome(string a) {
    string f;
    for(int i=0;i<a.size();i++){
        if('a'<=a[i] && a[i]<='z' || '0'<=a[i] && a[i]<='9')
        f.push_back(a[i]);
        if('A'<=a[i] && a[i]<='Z')
        f.push_back(a[i]+32);
    }
    int n = f.size();
    for(int i=0;i<n;i++){
    
        if(f[i]!=f[n-1-i])
        return 0;
    }
    return 1;
        
}

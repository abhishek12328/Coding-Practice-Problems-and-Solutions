/*Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

------------------------------------
------------------------------------
------------------------------------
------------------------------------*/

int Solution::lengthOfLastWord(const string a) {
    int count=0,max = INT_MIN;
    for(int i=0;i<a.size();i++){
        if(a[i]==' '){
            max = count;
            count = 0;
            while(i+1<a.size() && a[i+1]==' ')
            i++;
        }
        else
        count++;
    }
    if(max == INT_MIN || a[a.size()-1]!=' ')
    max = count;
    return max;
}

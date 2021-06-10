/*Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 

------------------------------------
------------------------------------
------------------------------------
------------------------------------*/




int Solution::strStr(const string a, const string b) {
    int m = a.size(),n=b.size();
    if(n==0 || m==0)
    return -1;
    if(a == b)
    return 0;
    for(int i=0;i<m-n+1;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(a[i+j]==b[j]){
                count++;
            }
        }
        if(count == n)
        return i;
    }
    return -1;
    
}

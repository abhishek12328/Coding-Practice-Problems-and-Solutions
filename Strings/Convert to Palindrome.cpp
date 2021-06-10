/*Given a string A consisting only of lowercase characters, we need to check whether it is possible to make this string a palindrome after removing exactly one character from this.

If it is possible then return 1 else return 0.

--------------------------------------------------
--------------------------------------------------
---------------------------------------------------
--------------------------------------------------*/


int Solution::solve(string a) {
    int n = a.size(),i,count = 0,j;
    for(i=0,j=n-1;i<=(n-1)/2 && i<j;i++,j--){
        if(a[i]!=a[j]){
            i--;
            count++;
        }
    }
    int b=0,c=0;
    if((count == 1 )||(count == 0 && n%2==1))
    b = 1;
    count = 0;
    for(i=0,j=n-1;i<=(n-1)/2 && i<j;i++,j--){
        if(a[i]!=a[j]){
            j++;
            count++;
        }
    }
    if(count == 1)
    c = 1;
    return b||c;

}

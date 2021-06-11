/*Given two binary strings, return their sum (also a binary string).


----------------------------------------------
----------------------------------------------
----------------------------------------------
----------------------------------------------*/





string Solution::addBinary(string a, string b) {
    int m = a.size(),carry = 0,n=b.size(),i,j;
    string ans;
    for(i=m-1,j=n-1; i>=0 && j>=0; i--,j--){
        int temp = a[i]+b[j]+carry - '0' - '0';
        if(temp == 0){
        ans = "0" + ans;
        carry = 0;
        }
        if(temp == 1){
        ans = "1" + ans;
        carry = 0;
        }
        if(temp == 2){
        ans = "0" + ans;
        carry = 1;
        }
        if(temp == 3){
        ans = "1" + ans;
        carry = 1;
        }
    }
    while(i>=0){
        int temp = a[i]-'0' + carry;
        if(temp == 0){
        ans = "0" + ans;
        carry = 0;
        }
        if(temp == 1){
        ans = "1" + ans;
        carry = 0;
        }
        if(temp == 2){
        ans = "0" + ans;
        carry = 1;
        }
        i--;
    }
    while(j>=0){
        int temp = b[j]-'0' + carry;
        if(temp == 0){
        ans = "0" + ans;
        carry = 0;
        }
        if(temp == 1){
        ans = "1" + ans;
        carry = 0;
        }
        if(temp == 2){
        ans = "0" + ans;
        carry = 1;
        }
        j--;
    }
    if(carry)
    ans = "1" + ans;
    return ans;
}

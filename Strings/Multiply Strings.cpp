/*Given two numbers represented as strings, return multiplication of the numbers as a string.

 Note: The numbers can be arbitrarily large and are non-negative.
Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer. 


---------------------------------------
---------------------------------------
---------------------------------------
---------------------------------------*/

string Solution::multiply(string a, string b) {
    
    int m = a.size(), n=b.size(),i=0,j=0,carry = 0;
    while(i<m && a[i] == '0') i++;
    if(i == m) return "0";
    while(j<n && b[j] == '0') j++;
    if(j == n) return "0";
    int k = m-1, l = n-1;
    string ans="0",t;
    while(k>=i && l>=j){
        carry = 0;
        string s = "";
        while(k>=i){
            int temp = carry + (b[l]-'0')*(a[k]-'0');
            s.insert(s.begin(),temp%10 + '0');
            carry = temp/10;
            k--;
        }
        if(carry)
        s.insert(s.begin(),carry+ '0');
        int zeros = n-1-l;
        while(zeros--) s.push_back('0');
        int c= ans.size()-1,d =s.size()-1;
        carry = 0;
        t = "";
        while(c>=0 || d>=0){
            int temp = carry + ((c>=0)?(ans[c]-'0'):0) + ((d>=0)?(s[d]-'0'):0);
            t.insert(t.begin(),(temp%10)+'0');
            carry = temp/10;
            c--; 
            d--;
        }
        if(carry)
        t.insert(t.begin(),carry+ '0');
        l--;
        k = m-1;
        ans = t;
    }
    return ans;
    
}

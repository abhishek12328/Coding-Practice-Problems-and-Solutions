/*Find if Given number is power of 2 or not.
More specifically, find if given number can be expressed as 2^k where k >= 1.

number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/


int Solution::power(string a){
    if(a == "1")
    return 0;

    if(a == "2")
    return 1;
    int n=a.size(),rem =0,temp,i=0;
    string q;

    while(i<n){
        temp = rem*10 + (a[i]-'0');
        if(temp%2 == 1)     rem = 1;
        else    rem = 0;
        if(temp!=1)
        q.push_back(temp/2+'0');
        if(temp==1)
        q.push_back('0');
        i++;
    }
    i=0;
    while(i<q.size() && q[i] == '0') i++;
    if(rem == 1)
    return 0;
    return power(q.substr(i));
}

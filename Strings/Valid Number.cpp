/*Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem

----------------------------------------------
----------------------------------------------
----------------------------------------------
----------------------------------------------*/


int Solution::isNumber(const string a) {
    int i,n=a.size(),num=0,power = 0,dec =0,space = 0;
    while(a[i] == ' ') i++;
    if(i>=n) return 0;
    if(a[i] == '-' || a[i] == '+') i++;
    if(i>=n) return 0;
    while(a[i]=='0') i++;
    while(i<n && !power){
        if(a[i] == '.'){
            if(dec || i==n-1 || a[i+1]<'0' || a[i+1]>'9')
            return 0;
            else
            dec = 1;
        }
        else if('0'<=a[i] && a[i]<='9'){
            num = 1;
        }
        else if(a[i] == 'e'){
            if(!num)
            return 0;
            else
            power = 1;
        }
        else if(a[i] == ' '){
        space = 1;
        i++;
        break;
        }
        else 
        return 0;
        i++;
    }
    if(space == 1){
        while(a[i] == ' ' && i<n) i++;
        if(i<n)
        return 0;
        else
        return 1;
    }
    if(i==n-1 && power)
    return 0;
    else if(power){
    if(a[i] == '-' || a[i] == '+') i++;
    if(i>=n) return 0;
    while(a[i]=='0') i++;
    while(i<n){
        if(a[i]<'0' || a[i]>'9')
        return 0;
        else if(a[i] == ' '){
        space = 1;
        i++;
        break;
        }
        i++;
    }
    if(space == 1){
        while(a[i] == ' ' && i<n) i++;
        if(i<n)
        return 0;
        else
        return 1;
    }
    }
    return 1;
}

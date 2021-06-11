/*Implement atoi to convert a string to an integer.

Example :

Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.

 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 

---------------------------------------
---------------------------------------
---------------------------------------
---------------------------------------*/




int Solution::atoi(const string a) {
    int ans=0,flag = 0,neg = 1,n=a.size();
    for(int i=0;i<n;i++){
        if(a[i] == '-' && flag == 0 && neg==1)
        neg = -1;
        
        else if(a[i] == '+' && flag == 0 && neg==1)
        neg = 1;
        else if('0'<=a[i] && a[i]<='9'){

        if(ans>INT_MAX/10){
            if(neg==1)
            return INT_MAX;
            else
            return INT_MIN;
        }
        ans = ans*10 + a[i]-'0';
        flag = 1;
        }
        else if(a[i] == ' ' && (flag == 1||neg == -1 ))
        return neg*ans;
        else{
            return neg * ans;
        }
    }
    return neg*ans;
}

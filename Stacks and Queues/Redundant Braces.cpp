/*Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.

---------------------------------------------------
---------------------------------------------------*/

int Solution::braces(string a){
    int n = a.size(),i,op=0;
    stack<char> s;
    for(i=0;i<n;i++){
        if(a[i] == '(')
        s.push(a[i]);
        else if((a[i] == '+' ||a[i] == '-' ||a[i] == '*' ||a[i] == '/' )&& (!s.empty()))
        s.pop();
    }
    return (!s.empty())?1:0;
}

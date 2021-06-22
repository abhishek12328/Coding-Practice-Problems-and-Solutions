/*Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.

----------------------------------------------------
----------------------------------------------------*/

int Solution::solve(string a) {
int n = a.size();
stack<char> st;
for(int i=0;i<n;i++){
if(a[i] == '(')
st.push('(');
else if(a[i] == ')' && !st.empty())
st.pop();
else
return 0;

}
if(st.empty())
return 1;
return 0;

}

/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

--------------------------------------
--------------------------------------*/

int Solution::evalRPN(vector<string> &a) {
    int n = a.size(),i,ans;
    stack<int> st;
    for(i=0;i<n;i++){
        if(a[i]=="+" ||a[i]=="-" ||a[i]=="*" ||a[i]=="/"){
            int temp2 = (st.top());
            st.pop();
            int temp1 = (st.top());
            st.pop();
            if(a[i]=="+")
            ans = temp1+temp2;
            if(a[i]=="-")
            ans = temp1-temp2;
            if(a[i]=="*")
            ans = temp1*temp2;
            if(a[i]=="/")
            ans = temp1/temp2;
            st.push(ans);
        }
        else
        {
            st.push(stoi(a[i]));
        }
    }
    return st.top();
}

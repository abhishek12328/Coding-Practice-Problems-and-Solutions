/*Given a string A representing an absolute path for a file (Unix-style).

Return the string A after simplifying the absolute path.

Note:

Absolute path always begin with ’/’ ( root directory ).

Path will not have whitespace characters.


---------------------------------------------
---------------------------------------------*/

string Solution::simplifyPath(string A) {
    deque<string>st;
        string temp;
        for(int i=0;i<A.size();i++){
            if(A[i]=='/'){
                if(temp==".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                    temp.clear();
                }else if(temp=="."){
                    temp.clear();
                }
                else {
                    if(!temp.empty()){
                    st.push_back(temp);
                    temp.clear();
                    }
                }
            }else{
                temp.push_back(A[i]);
            }
            
        }
       if(temp==".."){
                    if(!st.empty()){
                        st.pop_back();
                    }
                    temp.clear();
                }else if(temp=="."){
                    temp.clear();
                }
                else {
                    if(!temp.empty()){
                    st.push_back(temp);
                    temp.clear();
                    }
                }
        temp="/";
        while(!st.empty()){
            temp+=st.front();
            st.pop_front();
            if(!st.empty()){
                temp+="/";
            }
        }
        return temp;
}

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(!root)
            return ans;
        Node* temp = root;
        stack<Node*> st;
        stack<int> out;
        st.push(temp);
        while(!st.empty()){
           temp = st.top();
            st.pop();
            out.push(temp->val);
            for(int i=0;i<temp->children.size();i++){
                if(temp->children[i])
                st.push(temp->children[i]);
            }
        }
        while(!out.empty()){
            ans.push_back(out.top());
            out.pop();
        }
        return ans;
    }
};

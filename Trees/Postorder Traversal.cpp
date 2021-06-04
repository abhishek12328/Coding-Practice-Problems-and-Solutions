/*Given a binary tree, return the postorder traversal of its nodes’ values.

--------------------------------------
--------------------------------------
--------------------------------------
--------------------------------------*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*>st;
    vector<int>res;
    TreeNode* r=A;
    st.push(r);
    stack<int>out;
    while(!st.empty()){
        r=st.top();
        st.pop();
        out.push(r->val);
        if(r->left)st.push(r->left);
        if(r->right)st.push(r->right);
    }
    while(!out.empty()){
        res.push_back(out.top());
        out.pop();
    }
    return res;
}

/*Given a binary tree, return the preorder traversal of its nodes’ values.

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode* temp = A;
    while(temp||!st.empty()){
        while(temp){
            result.push_back(temp->val);
            st.push(temp);
            temp = temp->left;
        }
        temp = (st.top())->right;
        st.pop();
    }
    return result;
}

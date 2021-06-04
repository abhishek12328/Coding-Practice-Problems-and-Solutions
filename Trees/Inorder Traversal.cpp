/*Implement iterative inorder traversal of a tree

-------------------------------------
-------------------------------------
-------------------------------------
-------------------------------------*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*>st;
    TreeNode* r=A;
    vector<int>res;
    while(r!=NULL || !st.empty()){
        while(r!=NULL){
            st.push(r);
            r=r->left;
        }
            r=st.top();
            st.pop();
            res.push_back(r->val);
            r=r->right;
        
    }
    return res;
}

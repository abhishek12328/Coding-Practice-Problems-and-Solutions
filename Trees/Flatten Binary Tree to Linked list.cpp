/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* root) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(!root)
            return root;
        
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        TreeNode* temp;
        st.push(root);
        
        while(!st.empty()){
            temp = st.top();
            st.pop();
            q.push(temp);
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
        }
        temp = q.front();
        q.pop();
        while(!q.empty()){
            TreeNode* temp1 = q.front();
            q.pop();
            temp->left = NULL;
            temp->right = temp1;
            temp = temp->right;
        }
        
    return root;
}

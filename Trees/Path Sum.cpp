/*Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
------------------------------------------------
------------------------------------------------
------------------------------------------------
------------------------------------------------*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* a, int b) {
    if(!a->left && !a->right && b == a->val)
    return 1;
    if(a->left)
    if(hasPathSum(a->left,b-a->val)) return 1;
    if(a->right)
    if(hasPathSum(a->right,b-a->val)) return 1;
    return 0;
}

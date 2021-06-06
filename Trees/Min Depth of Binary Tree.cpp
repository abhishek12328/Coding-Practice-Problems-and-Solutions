/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 NOTE : The path has to end on a leaf node. 
 
 -------------------------------------------------
 -------------------------------------------------
 -------------------------------------------------
 -------------------------------------------------*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    
    if(!A)
    return INT_MAX;
    if(!A->left && !A->right)
    return 1;
    return min(1+minDepth(A->left),1+minDepth(A->right));
}

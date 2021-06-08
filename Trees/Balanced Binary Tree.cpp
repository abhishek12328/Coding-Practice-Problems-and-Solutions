/*Given a binary tree, determine if it is height-balanced.

 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

-----------------------------------------
-----------------------------------------
-----------------------------------------
-----------------------------------------*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode* A){
    if(!A)
    return 0;
    if(!A->left && !A->right)
    return 1;
    return max(1+height(A->left),1+height(A->right));
}
int Solution::isBalanced(TreeNode* A) {
    if(!A)
    return 1;
    if(abs(height(A->left)-height(A->right))>1) return 0;
    if(!isBalanced(A->left)) return 0;
    if(!isBalanced(A->right)) return 0;
    return 1;
}

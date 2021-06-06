/*Given a binary tree, invert the binary tree and return it.

Given binary tree

     1
   /   \
  2     3
 / \   / \
4   5 6   7
invert and return

     1
   /   \
  3     2
 / \   / \
7   6 5   4


-----------------------------------
-----------------------------------
-----------------------------------
-----------------------------------*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::invertTree(TreeNode* A) {
    if(!A)
    return NULL;
    TreeNode* temp;
    temp = A->right;
    A->right = A->left;
    A->left = temp;
    invertTree(A->left);
    invertTree(A->right);
    return A;
}

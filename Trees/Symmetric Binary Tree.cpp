/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

-----------------------------
-----------------------------
-----------------------------
-----------------------------*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 bool func(TreeNode* a, TreeNode* b){
     if(!a && !b) return 1;
     if((!a && b )|| (!b && a)) return 0;
     if(!func(a->left,b->right)) return 0;
     if(!func(a->right,b->left)) return 0;
     if(a->val!=b->val) return 0; 
     return 1;
 }
int Solution::isSymmetric(TreeNode* a) {
    if(!a)
    return 1;
    return func(a->left,a->right);
}

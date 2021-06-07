/*Given a binary tree A with N nodes.

You have to remove all the half nodes and return the final binary tree.

NOTE:

Half nodes are nodes which have only one child.
Leaves should not be touched as they have both children as NULL.

-----------------------------------------------
-----------------------------------------------
-----------------------------------------------
-----------------------------------------------*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* myfunc(TreeNode* c){
    if(!c)
    return NULL;
    if((!c->right && !c->left))
    return c;
    c->left = myfunc(c->left);
    c->right = myfunc(c->right);
    if(c->left && c->right)
    return c;
    if(c->left)
    return c->left;
    if(c->right)
    return c->right;
 }
TreeNode* Solution::solve(TreeNode* a) {
    if(!a || (!a->left && !a->right))
    return a;
    return myfunc(a);
    
}

/*Given two Binary Trees A and B, you need to merge them in a single binary tree.

The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

Otherwise, the non-null node will be used as the node of new tree.

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
 TreeNode* myfunc(TreeNode* a, TreeNode *b){
     int aval = 0,bval = 0;
     if(a)
     aval = a->val;
     if(b)
     bval = b->val;
     TreeNode *temp;
     if(a || b)
     temp = new TreeNode(aval + bval);
     if(a && a->left && b && b->left)
     temp->left = myfunc(a->left,b->left);
     else if(a && a->left)
     temp->left = myfunc(a->left,NULL);
     else if(b && b->left)
     temp->left = myfunc(NULL,b->left);
     if(a && a->right && b && b->right)
     temp->right = myfunc(a->right,b->right);
     else if(a && a->right)
     temp->right = myfunc(a->right,NULL);
     else if(b && b->right)
     temp->right = myfunc(NULL,b->right);    
     return temp;
 }
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    return myfunc(A,B);
}

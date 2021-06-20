/*Given a binary tree T, find the maximum path sum.

The path may start and end at any node in the tree.

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

 int myfunc(TreeNode* a, int& maxi){
     if(a == NULL)
     return 0;
     int t1 = myfunc(a->left,maxi);
     int t2 = myfunc(a->right,maxi);
     int temp = a->val+max(t1,max(t2,0));
     maxi = max(maxi,max(a->val+t1+t2,temp));
     return temp;
 }

int Solution::maxPathSum(TreeNode* a) {
    int maxi = INT_MIN;
    myfunc(a,maxi);
    return maxi;

}

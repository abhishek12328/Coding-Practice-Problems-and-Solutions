/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 ------------------------------------------------
 ------------------------------------------------*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

map <pair<TreeNode*,bool>,int> m;

class Solution {
public:
    
    int myfunc(TreeNode* root, int flag){
        if(m[make_pair(root,flag)])
            return m[make_pair(root,flag)];
        
        int temp=0,temp1=0,ans =0 ;
        if(flag)
            ans = root->val;
        if(root->left){
           if(flag)
               temp = myfunc(root->left,0);
            else
               temp = max( myfunc(root->left,0),myfunc(root->left,1));
        }
        if(root->right){
           if(flag)
               temp1 = myfunc(root->right,0);
            else
               temp1 = max( myfunc(root->right,0),myfunc(root->right,1));
        }
        return m[make_pair(root,flag)] = ans + temp + temp1;
        
    }
    
    int rob(TreeNode* root) {
           return max(myfunc(root,0),myfunc(root,1));       
    }
};

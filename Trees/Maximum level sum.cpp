/*Given a Binary Tree denoted by root node A having integer value on nodes. You need to find maximum sum level in it.

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
int Solution::solve(TreeNode* a) {
    queue<TreeNode*> q;
    q.push(a);
    TreeNode* temp;
    int max=INT_MIN,sum;
    while(!q.empty()){
        int n = q.size();
        sum = 0;
        while(n--){
            temp = q.front();
            q.pop();
            sum+=temp->val;
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        if(max<sum)
        max = sum;
    }
    return max;
}

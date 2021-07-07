/*Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).

===============================================================
===============================================================*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(A);
    vector<vector<int>> v1;
    vector<int> v;
    int n;
    while(!q.empty()){
        n = q.size();
        while(n--){
            temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
        }
        v1.push_back(v);
        v.clear();
    }
    return v1;
}

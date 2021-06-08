/*Given a binary tree, return the reverse level order traversal of its nodes values. (i.e, from left to right and from last level to starting level).

-------------------------------------------
-------------------------------------------
-------------------------------------------
-------------------------------------------*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    TreeNode* temp;
    queue<TreeNode*> q;
    q.push(A);
    vector<vector<int>> v1;
    vector<int> v,v2;
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
    for(int i=v1.size()-1;i>=0;i--)
    v2.insert(v2.end(),v1[i].begin(),v1[i].end());
    return v2;
}

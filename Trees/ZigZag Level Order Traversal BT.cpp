/*Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

-------------------------------------
-------------------------------------
-------------------------------------
-------------------------------------*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    TreeNode* temp;
    vector<int> t;
    t.push_back(A->val);
    vector<vector<int>> v;
    v.push_back(t);
    q.push(A);
    int i=0;
    t.clear();
    while(!q.empty()){
        int n = q.size();
        while(n--){
            temp = q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                t.push_back(temp->left->val);
            }
            if(temp->right){
                q.push(temp->right);
                t.push_back(temp->right->val);
            }
        }
        if(i%2==0){
            reverse(t.begin(),t.end());
        }
        v.push_back(t);
        t.clear();
        i++;
    }
    v.erase(v.begin()+v.size()-1);
    return v;
}

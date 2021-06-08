/*Problem Description

Given a binary tree A of integers. Return an array of integers representing the right view of the Binary tree.

Right view of a Binary Tree: is a set of nodes visible when the tree is visited from Right side.

----------------------------------------
----------------------------------------
----------------------------------------
----------------------------------------*/


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
    stack<TreeNode*> s,s1;
    map<int , vector<int>> m;
    TreeNode* temp = A;
    s.push(temp);
    vector<int> result;
    result.push_back(A->val);
    while(!s.empty()){
        while(!s.empty()){
            temp = s.top();
            s.pop();
            if(temp->right)
            s1.push(temp->right);
            if(temp->left)
            s1.push(temp->left);
        }
        while(!s1.empty()){
            s.push(s1.top());
            s1.pop();
        }
        if(!s.empty())
        result.push_back((s.top())->val);
    }
    return result;
}

/*Given a binary search tree, write a function to find the kth smallest element in the tree.

------------------------------------------
------------------------------------------
------------------------------------------
------------------------------------------*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::kthsmallest(TreeNode* A, int B) {
    stack<TreeNode*> s;
    TreeNode* temp=A;
    vector<int> result;
    while(temp||!s.empty()){
        while(temp){
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();
        result.push_back(temp->val);
        temp = temp->right;
    }
    sort(result.begin(),result.end());
    return result[B-1];
    
}

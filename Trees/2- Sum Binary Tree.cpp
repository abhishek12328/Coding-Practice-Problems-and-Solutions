/*Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.

--------------------------------------------
--------------------------------------------
--------------------------------------------
--------------------------------------------*/



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::t2Sum(TreeNode* A, int B) {
    stack<TreeNode *> l, r;
    TreeNode *lnode, *rnode;
    TreeNode *cur = A;
    while (cur) {
        l.push(cur);    cur = cur->left;
    }
    cur = A;
    while (cur){ 
        r.push(cur);    cur = cur->right;
    }
    while (!l.empty() && !r.empty()) {
        lnode = l.top(), rnode = r.top();
        if (lnode->val+rnode->val == B && lnode != rnode)    return 1;
        else if (lnode->val+rnode->val > B) {
            r.pop();
            rnode = rnode->left;
            while (rnode) 
                r.push(rnode),    rnode = rnode->right;
        } else {
            l.pop();
            lnode = lnode->right;
            while (lnode) 
                l.push(lnode),    lnode = lnode->left;
        }
    }
    return 0;
}

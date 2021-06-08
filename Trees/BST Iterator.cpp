/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 

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

stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
    
    TreeNode* curr = root;
    while(curr)
    s.push(curr), curr = curr->left;


}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(!s.empty())
    return 1;
    else
    return 0;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* temp,*temp1;
        temp = s.top();
        s.pop();
        temp1 = temp->right;
        while(temp1)
        s.push(temp1), temp1 = temp1->left;
        return temp->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 


-------------------------------------------------
-------------------------------------------------
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

TreeNode* myfunc(const vector<int> &A,int start,int end){
    if (start > end) 
    return NULL;
    int m = (start + end)/2;
    TreeNode* temp = new TreeNode(A[m]);
    temp->left = myfunc(A,start,m-1);
    temp->right = myfunc(A,m+1,end);
    return temp;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    int n = A.size();
    if(n==0) return NULL;
    return myfunc(A,0,n-1);
}

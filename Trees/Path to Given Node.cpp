/*Given a Binary Tree A containing N nodes.

You need to find the path from Root to a given node B.

NOTE:

No two nodes in the tree have same data values.
You can assume that B is present in the tree A and a path always exists.

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
vector<int> Solution::solve(TreeNode* a, int b) {
    vector<int> v1,v2,v3;
    v1.push_back(a->val);
    
    if(a->val == b || (!a->left && !a->right))
    return v1;
    
    if(a->left){
        v3 = solve(a->left,b);
        if(v3[v3.size()-1] == b)
        v1.insert(v1.end(),v3.begin(),v3.end());
    }
    if(a->right){
        v2 = solve(a->right,b);
        if(v2[v2.size()-1] == b)
        v1.insert(v1.end(),v2.begin(),v2.end());
    }
    

    return v1;
    
}

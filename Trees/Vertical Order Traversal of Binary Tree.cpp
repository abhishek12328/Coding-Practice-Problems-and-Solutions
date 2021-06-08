/*Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.

---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------
---------------------------------------------------------*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A==NULL)return {};
    queue<pair<TreeNode*,int>>q;
    map<int,vector<int>>m;
    q.push(make_pair(A,0));
    while(!q.empty()){
        pair<TreeNode*,int>temp=q.front();
        q.pop();
        TreeNode* n=temp.first;
        int k=temp.second;
        m[k].push_back(n->val);
        if(n->left){
            q.push(make_pair(n->left,k-1));
        }
        if(n->right){
            q.push(make_pair(n->right,k+1));
        }
    }
    int s=m.size(),i=0;
    vector<vector<int>>res(s);
    for(auto x:m){
        for(int j=0;j<x.second.size();j++){
            res[i].push_back(x.second[j]);
        }
        i++;
    }
    return res;
}

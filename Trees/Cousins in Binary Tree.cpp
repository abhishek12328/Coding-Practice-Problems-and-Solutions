/*Given a Binary Tree A consisting of N nodes.

You need to find all the cousins of node B.

NOTE:

Siblings should not be considered as cousins.
Try to do it in single traversal.
You can assume that Node B is there in the tree A.
Order doesn't matter in the output.

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
vector<int> Solution::solve(TreeNode* a, int b) {
    queue<TreeNode*> q;
    vector<int> v1,v2;
    TreeNode *temp;
    int flag = 0,flag1 = 0;
    int rem;
    q.push(a);
    while(!q.empty()){
        int n=q.size();
        while(n--){
            temp = q.front();
            q.pop();
            if(temp->left){
                if(temp->left->val == b){
                flag =1;
                if(temp->right){
                flag1 = 1;
                rem = temp->right->val;
                
                }
                }
                q.push(temp->left);
                if(!(temp->left->val == b))
                v1.push_back(temp->left->val);
            }
            if(temp->right){
                if(temp->right->val == b){
                flag =1;
                if(temp->left){
                flag1 = -1;
                rem = temp->left->val;
                }
                }
                q.push(temp->right);
                if(!(temp->right->val == b))
                v1.push_back(temp->right->val);
            }
        }
        if(flag == 1){
            v2.insert(v2.end(),v1.begin(),v1.end());
            break;
        }
        v1.clear();
        
    }
    
    if(flag == 0)
    return v2;
    if(flag1 == 0)
    return v2;
    else{
        for(int i=0;i<v2.size();i++){
            if(v2[i] == rem){
            v2.erase(v2.begin()+i);
            }
        }
    }
    return v2;
    
}

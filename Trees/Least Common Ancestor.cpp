/*Find the lowest common ancestor in an unordered binary tree given two values in the tree.

 Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 
   
   
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
 
 int myfunc(TreeNode* A,int B,int C){
    if(A->val==B)    return B;
    else if(A->val == C)    return C;
    int x=-1,y=-1;
    if(A->left)
    x = myfunc(A->left,B,C);
    if(A->right)
    y = myfunc(A->right,B,C);
    
    if( (x==B && y==C) || (x==C && y==B))    return A->val;
    else if(x==-1 && y==-1)    return -1;
    else if(x!=-1 && y==-1)    return x;
    else if(y!=-1 && x==-1)    return y;
    return -1;
 }
 
 int ispresent(TreeNode* a,int c){
     if(a->val == c)     return 1;
     if(a->left && ispresent(a->left,c)) return 1;
     if(a->right && ispresent(a->right,c)) return 1;
     return 0;
 }
 
int Solution::lca(TreeNode* A, int B, int C) {
    if(!ispresent(A,B)) return -1;
    if(!ispresent(A,C)) return -1;
    
    return myfunc(A,B,C);
    
}

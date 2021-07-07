/*Given a tree with N nodes labelled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if A[i] is 1 then ithnode is good else if A[i] is 0 then ith node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root to leaf paths in the tree that contain not more than C good nodes.

NOTE:

Each edge in the tree is bi-directional.
*/


int dfs(vector<vector<int>> &adj, vector<bool> &v, int c, int src,vector<int> &A){
    v[src] = true;
    c = c - A[src];
    if(c<0) return 0;
    if(adj[src].size() == 1)
    return 1;
    int count = 0;
    for(int j=0;j<adj[src].size();j++){
        if(!v[adj[src][j]]){
        count += dfs(adj,v,c,adj[src][j],A);
        }
    }
    return count;
}

int Solution::solve(vector<int> &A, vector<vector<int> > &b, int c) {
    int n = A.size();
    vector<bool> visited(n,false);
    vector<vector<int>> adj(n);
    for(int i=0;i<b.size();i++){
    adj[b[i][0]-1].push_back(b[i][1]-1);
    adj[b[i][1]-1].push_back(b[i][0]-1);
    }
    return dfs(adj,visited,c,0,A);

}

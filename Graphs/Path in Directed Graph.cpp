/*Given an directed graph having A nodes labelled from 1 to A containing M edges given by matrix B of size M x 2such that there is a edge directed from node

B[i][0] to node B[i][1].

Find whether a path exists from node 1 to node A.

Return 1 if path exists else return 0.

NOTE:

There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

--------------------------------------------------------
--------------------------------------------------------*/

int dfs(vector<vector<int>> &v,int src,vector<bool>& visited){
    visited[src] = true;
    if(src == v.size()-1)
    return true;
    for(int i=0;i<v[src].size();i++){
        if(!visited[v[src][i]])
        if(dfs(v,v[src][i],visited)) return true;
    }
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<bool> visited(a,false);
    vector<vector<int>> v(a);
    for(int i=0;i<b.size();i++)
    v[b[i][0]-1].push_back(b[i][1]-1);
    int t = dfs(v,0,visited); 

    return t;
}

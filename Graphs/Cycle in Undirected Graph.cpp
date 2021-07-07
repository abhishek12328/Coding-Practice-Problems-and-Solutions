/*Given an undirected graph having A nodes labelled from 1 to A with M edges given in a form of matrix B of size M x 2 where (B[i][0], B[i][1]) represents two nodes B[i][0] and B[i][1] connected by an edge.

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast three nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.

--------------------------------------------------------
--------------------------------------------------------*/

bool iscycle(vector<vector<int>> & adj, vector<int>& visited, int src, int parent){
    visited[src] = true;
    for(auto i=adj[src].begin();i!=adj[src].end();i++){
        if(!visited[*i]){
          if(iscycle(adj,visited,*i,src)) return true;
        }
        else if(*i != parent) return true;
    }
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<vector<int>> adj(a+1);
    vector<int> visited(a+1,false);
    for(int i=0;i<b.size();i++){
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    
    for(int i=1;i<=a;i++){
        if(!visited[i])
        if(iscycle(adj,visited,i,-1)) return true;
    }
    return false;
    
}

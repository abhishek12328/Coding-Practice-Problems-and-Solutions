/*Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


-------------------------------------------
-------------------------------------------*/


bool iscycle(vector<vector<int>>& adj, vector<int>& visited, vector<int>& stak, int src){
    stak[src]  = true;
    visited[src] = true;
    for(auto i= adj[src].begin();i!=adj[src].end();i++){
        if(stak[*i] == true) return true;
        if(!visited[*i])
        if(iscycle(adj, visited, stak, *i)) return true;
    }
    stak[src] = false; 
    return false;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    vector<vector<int>> adj(a+1);
    vector<int> visited(a+1,false);
    vector<int> stak(a+1,false);
    for(int i=0;i<b.size();i++)
    adj[b[i][0]].push_back(b[i][1]);
    
    for(int i=1;i<=a;i++){
        if(!visited[i])
        if(iscycle(adj,visited,stak,i)) return true;
    }
    return false;
}

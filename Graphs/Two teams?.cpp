/*There are A people numbered 1 to A in a football academy.
The coach of the academy wants to make two teams (not necessary of equal size) but unfortunately, not all people get along, and several refuse to be put on the same team as that of their enemies.

Given a 2-D array B of size M x 2 denoting the enemies i.e B[i][0] and B[i][1] both are enemies of each other.

Return 1 if it possible to make exactly two teams else return 0.

------------------------------------------------
------------------------------------------------*/

bool isbipartite(vector<vector<int>> & adj, vector<int>& visited, int src, int parent,vector<int>& color){
    visited[src] = true;
    
    for(auto i=adj[src].begin();i!=adj[src].end();i++){
        if(!visited[*i]){
            color[*i] = -color[src];
          if(isbipartite(adj,visited,*i,src,color)){
               return true;
          }
        }
        else if(*i != parent) {
           if(color[*i] == color[src])
               return true;
          }
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
    vector<int> color(a+1,0);
    
    for(int i=1;i<=a;i++){
        if(!visited[i]){
            color[i] = 1;
        if(isbipartite(adj,visited,i,-1,color)) return false;
        }
    }
    return true;
    
}

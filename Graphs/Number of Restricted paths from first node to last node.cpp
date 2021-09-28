/*There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.*/

class Solution {
public:
    
    
    void dfs(int s,vector<vector<pair<int,int>>>& v,vector<int> & ans,vector<int>& dist){
  
        for(auto k:v[s]){
            if(dist[k.first]<dist[s]){
                
                if(k.first!=ans.size()-1 && ans[k.first] == -1)
                dfs(k.first,v,ans,dist);
                if(ans[s]==-1)
                ans[s] = (ans[k.first])%(1000000007);
                else{
                    ans[s] = (ans[s]+ans[k.first])%(1000000007);
                }
            }
        }
    }
    vector<int> dijkstra(vector<vector<pair<int,int>>>& v,int src){
        vector<int> dist(v.size(),INT_MAX);
        dist[src] = 0; 
        vector<bool> in(v.size(),false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        
        while(!pq.empty()){
        
            int n = pq.top().second;
            pq.pop();
            if(in[n]==true)
                continue;
            in[n] = true;
            for(auto k:v[n]){
                if(!in[k.first] && dist[k.first]>dist[n]+k.second){
                    dist[k.first]=dist[n]+k.second;
                    pq.push({dist[k.first],k.first});
                }
            }
        }
        return dist;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> v(n);
        for(auto k:edges){
            v[k[0]-1].push_back({k[1]-1,k[2]});
            v[k[1]-1].push_back({k[0]-1,k[2]});
        }
      
        vector<int> dist = dijkstra(v,n-1);
        vector<int> ans(n,-1);
        ans[n-1] = 1;
         dfs(0,v,ans,dist);
        return ans[0];
    }
};

/*There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/

class Solution {
public:
    bool dfs(vector<vector<int>>& v,int s,vector<bool> &visited,vector<int>& out){
        visited[s] = true;
        if(v[s].size()==0){
            out.push_back(s);
            return true;
        }
        bool temp = true;
        for(auto k:v[s]){
            if(visited[k]){
                if(find(out.begin(),out.end(),k)==out.end())
                temp = false;
            }
                
            if(!visited[k] && !dfs(v,k,visited,out)){
                temp = false;
            }
        }
        if(temp){
            out.push_back(s);
            return true;
        }
        return false;
        
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> out1(n,false);
        vector<int> out;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++)
        if(!visited[i]) dfs(graph,i,visited,out);
        sort(out.begin(),out.end());
        return out;
        
        
    }
};

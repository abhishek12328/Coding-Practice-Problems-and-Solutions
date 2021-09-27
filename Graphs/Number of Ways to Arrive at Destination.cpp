/*You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7. */

class Solution {
public:
    int minDistance(vector<long long> dist, bool sptSet[],int V){
        long long min = 1000000000000000, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }
 
    
    int dijkstra(vector<vector<int>> graph, int src){
        int V = graph.size();
        vector<long long> dist(V); 
        bool sptSet[V]; 
        vector<long long> ans(V,0);
            ans[0] = 1;
        for (int i = 0; i < V; i++){
            dist[i] = 1000000000000000;
        sptSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count <V-1; count++) {
            int u = minDistance(dist, sptSet,V);
            sptSet[u] = true;
            cout << u << " " << dist[u] << "  ";
            for (int v = 0; v < V; v++){
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] <= dist[v]){
                    
                    if(dist[u] + graph[u][v] == dist[v])
                    ans[v] = (ans[v] + ans[u])%(1000000007);
                    else if(dist[u] + graph[u][v] < dist[v])
                    ans[v] = ans[u];
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        cout << endl;
        return ans[V-1];
    }
    
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> v(n,vector<int>(n,0));
        int k = roads.size();
        for(int i=0;i<k;i++){
            v[roads[i][0]][roads[i][1]] = roads[i][2];
            v[roads[i][1]][roads[i][0]] = roads[i][2];
        }
        return dijkstra(v,0);
    }
};

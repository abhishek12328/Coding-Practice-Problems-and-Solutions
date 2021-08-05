/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 ------------------------------------------------
 ------------------------------------------------*/

class Solution {
public:
int minDistance(vector<int> dist, bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < dist.size(); v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
vector<int> dijkstra(vector<vector<int>> graph, int src)
{
    vector<int> dist(graph.size()); 
 
    bool sptSet[graph.size()]; 
 
    for (int i = 0; i < graph.size(); i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    dist[src] = 0;
 
    for (int count = 0; count < graph.size() - 1; count++) {

        int u = minDistance(dist, sptSet);
 
        sptSet[u] = true;
 
        for (int v = 0; v < graph.size(); v++)
 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    return dist;
}
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

 

    vector<vector<int>> v(n,vector<int>(n,0));
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]][edges[i][1]] = edges[i][2]; 
            v[edges[i][1]][edges[i][0]] = edges[i][2];
        }

   
    vector<int> ans(n,0);
        int a=INT_MAX,b;
    for(int i=0;i<n;i++){
       
        vector<int> t = dijkstra(v, i);
        for(int j=0;j<n;j++){
            cout << t[j] << " "; 
            if(j!=i && t[j]<=distanceThreshold)
                ans[i]++;
        }
        cout << endl;
        cout << ans[i] << " ";
        if(a>=ans[i]){
            a = ans[i];
            b = i;
        }
    }
        
 
    return b;

    }
};

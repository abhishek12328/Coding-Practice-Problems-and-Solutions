/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n,vector<int>(n,1000000));
        for(int i=0;i<edges.size();i++){
            distance[edges[i][0]][edges[i][1]] = edges[i][2]; 
            distance[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++)   distance[i][i] = 0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
                }
            }
        }
        int a=INT_MAX,b;
        for(int i=0;i<n;i++){
            int temp =0;
            for(int j=0;j<n;j++){
                if(j!=i && distance[i][j]<=distanceThreshold)
                    temp++;
            }
            if(a>=temp){
                a = temp;
                b = i;
            }
        }
        return b;
    }
};

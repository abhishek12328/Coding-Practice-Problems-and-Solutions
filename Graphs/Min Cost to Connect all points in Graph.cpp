/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            adj[i].push_back(j);
            adj[j].push_back(i);
            }
        }
        vector<bool> inmst(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> key(n,INT_MAX);
        
        key[0] = 0;
        int ans=0;
        int parent[n];
        while(!pq.empty()){
            auto temp = pq.top(); 
            pq.pop();
            int s = temp.second;
            if(inmst[s] == true)
                continue;
            
            inmst[s]=true;
            ans += temp.first;
            
            for(auto k:adj[s]){                
                if(inmst[k]==false && key[k]>abs(points[k][0]-points[s][0])+abs(points[s][1]-points[k][1])){
                    pq.push({abs(points[k][0]-points[s][0])+abs(points[s][1]-points[k][1]),k});
                    key[k] = abs(points[k][0]-points[s][0])+abs(points[s][1]-points[k][1]);
                    parent[k] = s;
                }
            }
        }
        
        return ans;
    }
};

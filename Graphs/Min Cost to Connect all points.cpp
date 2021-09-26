/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.*/


class Solution {
public:
    
    int find(int x,vector<int>& link){
        while(link[x]!=x) x= link[x];
        return x;
    }
    
    bool same(int x,int y, vector<int>& link){
        return find(x,link)==find(y,link);
    }
    
    void unite(int x,int y,vector<int> &link,vector<int>& size){
        int a = find(x,link);
        int b = find(y,link);
        if(a<b) swap(a,b);
        link[b] = a;
        size[a] += size[b];
    }
    
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> v;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
            }
        }
        sort(v.begin(),v.end());
        vector<int> link(points.size());
        for(int i=0;i<n;i++) link[i] = i;
        vector<int> size(points.size(),1);
        int ans=0;
        for(int i=0;i<v.size();i++){
            int src = v[i][1];
            int dest = v[i][2];
            if(!same(src,dest,link)){
                ans += v[i][0];
                unite(src,dest,link,size);
            } 
        }
        return ans;
    }
};

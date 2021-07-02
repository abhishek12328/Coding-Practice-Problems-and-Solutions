class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        int n = points.size(),i;
        for(i=0;i<n;i++){
            double distance = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push(make_pair(distance,make_pair(points[i][0],points[i][1])));
        }
        vector<vector<int>> ans(k,vector<int>(2));
        
        for(i=0;i<k;i++){
            auto t = pq.top();
            pq.pop();
            ans[i][0] = t.second.first;
            ans[i][1] = t.second.second;
        }
        return ans;
        
    }
};

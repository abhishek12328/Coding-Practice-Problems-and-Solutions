/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

class Solution {
public:
    bool iscycle(vector<vector<int>> &v,int s,vector<bool>& st,vector<bool> &visited){
        visited[s]=true;
        st[s] = true;
        for(auto k:v[s]){
            if(st[k]==true)
                return true;
            if(!visited[k] && iscycle(v,k,st,visited))
            return true;
        }
        st[s] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        for(int i=0;i<p.size();i++){
            v[p[i][0]].push_back(p[i][1]);
        }
        vector<bool> visited(n,false);
        vector<bool> st(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i] && iscycle(v,i,st,visited))
                return false;
        }
        return true;
      
    }
};

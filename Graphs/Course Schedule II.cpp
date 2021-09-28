/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 */

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> v(n);
        vector<int> indeg(n,0);
        vector<int> ans;
        for(auto k:p){
          v[k[1]].push_back(k[0]);
        indeg[k[0]]++;
        } 
        
        queue<int> q;
        int count =0;
        for(int i=0;i<n;i++)
            if(indeg[i]==0){
                ans.push_back(i);
                q.push(i);
                count++;
            }
       
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto k:v[t]){
                indeg[k]--;
                if(indeg[k]==0){
                    q.push(k);
                    ans.push_back(k);
                    count++;
                }
            }
        }
        vector<int> z;
        return (count==n)?ans:z;
        
    }
};

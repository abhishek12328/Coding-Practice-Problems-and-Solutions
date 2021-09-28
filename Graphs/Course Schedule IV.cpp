/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.*/

class Solution {
public:
    vector<int>adj[100005];
    int vis[100005];
    unordered_set<int>ans[100005];
    void recur(int x,int par)
    {
        vis[x]=1;
        if(par!=x)
        ans[par].insert(x);  //Par is prerequisite for all x it is visiting
        for(auto it:adj[x])
        {
            if(vis[it]==0)
                recur(it,par);
        }
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for(auto it:prerequisites)
            adj[it[0]].push_back(it[1]);
        for(int i=0;i<n;i++)
        {
            recur(i,i);
           memset(vis,0,sizeof(vis));
        }
        vector<bool>b;
        for(auto it:queries)
        {
            if(ans[it[0]].find(it[1])!=ans[it[0]].end())
                b.push_back(true);
            else
                b.push_back(false);
        }
        return b;
    }
};

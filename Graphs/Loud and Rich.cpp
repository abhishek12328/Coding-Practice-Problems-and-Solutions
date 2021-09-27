/*There is a group of n people labeled from 0 to n - 1 where each person has a different amount of money and a different level of quietness.

You are given an array richer where richer[i] = [ai, bi] indicates that ai has more money than bi and an integer array quiet where quiet[i] is the quietness of the ith person. All the given data in richer are logically correct (i.e., the data will not lead you to a situation where x is richer than y and y is richer than x at the same time).

Return an integer array answer where answer[x] = y if y is the least quiet person (that is, the person y with the smallest value of quiet[y]) among all people who definitely have equal to or more money than the person x.*/
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
         int n = quiet.size();
        vector<int> indg(n,0), ans(n,INT_MAX);
        vector<vector<int>> g(n);
        queue<int> q;
        
        
        for(int i=0;i<richer.size();i++){
            g[richer[i][0]].push_back(richer[i][1]);
            indg[richer[i][1]]++;
        }
       
       
        for(int i=0;i<n;i++){
            ans[i]=i;
            if(indg[i]==0)
                q.push(i);
        }
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            for(int i : g[curr]){
                
                if(quiet[ans[i]] > quiet[ans[curr]])
                    ans[i] = ans[curr];
                indg[i]--;
                if(indg[i]==0)
                    q.push(i);
            }
        }
        return ans;
    }

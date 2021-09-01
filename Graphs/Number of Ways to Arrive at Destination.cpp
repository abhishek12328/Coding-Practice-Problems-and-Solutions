/*You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7. */

 long long MOD=1e9+ 7;
    int countPaths(int n, vector<vector<int>>& roads) {
      vector<long long> dis(n,1e15);
        
        vector<long long> ways(n,1);
        dis[0]=0;
        ways[0]=1;
       
        vector<vector<pair<long long,long long>>> adj(n);
       
        for(auto x: roads){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]}); 
        }
        
         priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
 
	dis[0]=0;
	
	q.push({0,0});
	
     long long disprev,prev,currnum,currw;
 
	while(!q.empty()){
	    disprev=q.top().first;
	    prev=q.top().second;
	    
	    q.pop();
        if (dis[prev]<disprev) continue;
	    for(auto x: adj[prev]){
	          currnum=x.first;
              currw=x.second;
           
	        if(dis[prev] + currw < dis[currnum]){
	            dis[currnum]=dis[prev] + currw;
	            q.push({dis[currnum],currnum});   
                ways[currnum]=ways[prev]%MOD;
	        }
            else if(dis[prev] + currw == dis[currnum]){
                ways[currnum]+=ways[prev];
                ways[currnum]%=MOD;
            }
	    }
	}
	
      
        
        return ways[n-1];

    }

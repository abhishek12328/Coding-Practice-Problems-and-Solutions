/*Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.

*/


int Solution::knight(int a, int b, int c, int d, int e, int f){
    if(c== e && d==f)
    return 0;
    vector<vector<int>> visited(a+1,vector<int>(b+1,false));
    queue<pair<int,int>> q;
    q.push(make_pair(c,d));
    visited[c][d] = 1;
    int dist = 0;
    while(!q.empty()){
        int n = q.size();
        dist++;
        while(n--){
            auto t = q.front();
            q.pop();
            vector<int> row = {-2,-1,-2,-1,2,1,2,1};
            vector<int> col = {-1,-2,1,2,-1,-2,1,2};
            for(int i=0;i<8;i++){
                if(t.first+row[i]>0 && t.first+row[i]<=a && t.second+col[i]>0 && t.second+col[i]<=b && !visited[t.first+row[i]][t.second+col[i]] ){
                    if(t.first+row[i] == e && t.second+col[i]==f)
                    return dist;
                    visited[t.first+row[i]][t.second+col[i]] = 1;
                    q.push(make_pair(t.first+row[i],t.second+col[i]));
                }
                
            }
        }
    }
    return -1;
}

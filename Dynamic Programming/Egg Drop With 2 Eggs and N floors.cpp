/*You are given two identical eggs and you have access to a building with n floors labeled from 1 to n.

You know that there exists a floor f where 0 <= f <= n such that any egg dropped at a floor higher than f will break, and any egg dropped at or below floor f will not break.

In each move, you may take an unbroken egg and drop it from any floor x (where 1 <= x <= n). If the egg breaks, you can no longer use it. However, if the egg does not break, you may reuse it in future moves.

Return the minimum number of moves that you need to determine with certainty what the value of f is.

 -----------------------------------------------------------------
 -----------------------------------------------------------------*/


class Solution {
public:
    
    int myfunc(vector<vector<int>> & dp,int f,int e){
        if(f==0 || f==1)
            return dp[f][e] = f;
        if(e == 1)
            return dp[f][e] = f;
        if(dp[f][e] != -1)
            return dp[f][e];
        int mi = INT_MAX;
        for(int k=1;k<=f;k++){
            int temp = 1+max(myfunc(dp,k-1,1),myfunc(dp,f-k,2));
            if(temp<mi)
                mi = temp;
        }
        return dp[f][e] = mi;
        
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(10000,vector<int>(3,-1));
        return myfunc(dp,n,2);   
    }
};

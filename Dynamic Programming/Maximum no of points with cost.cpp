/*You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

-----------------------------------------------------------
------------------------------------------------------------*/


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int ans,m=points.size(),n= points[0].size();
        vector<vector<long long>> opt(m,vector<long long>(n,0)),add(m,vector<long long>(n,0)),sub(m,vector<long long>(n,0));
        
        for(int i=0;i<n;i++){
            opt[0][i] = points[0][i];
            add[0][i] = points[0][i]+i;
            sub[0][i] = points[0][i]-i;
        }
        
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
            add[i][j] = points[i][j]+j;
            sub[i][j] = points[i][j]-j;
            }
            vector<long long> madd = add[i-1];            
            vector<long long> msub = sub[i-1];
            long long ma = INT_MIN;
            for(int j=0;j<n;j++){
                if(add[i-1][j]>ma)
                    ma = add[i-1][j];
                madd[j] = ma;  
            }
            ma = INT_MIN;
            for(int j=n-1;j>=0;j--){
                if(sub[i-1][j]>ma)
                    ma = sub[i-1][j];
                msub[j] = ma;  
            }
            for(int j=0;j<n;j++){
                opt[i][j] = max(sub[i][j]+madd[j],add[i][j]+msub[j]);
                add[i][j] = opt[i][j]+j;
                sub[i][j] = opt[i][j]-j;
            }
            

        }
        long long ma=INT_MIN;
        for(int j=0;j<n;j++){
            if(opt[m-1][j]>ma)
                ma=opt[m-1][j];
        }
        return ma;
    }
};

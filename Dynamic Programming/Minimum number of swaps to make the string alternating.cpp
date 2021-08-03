/*Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

 -----------------------------------------------------------------
 -----------------------------------------------------------------*/

class Solution {
public:
    int minSwaps(string s) {
        
        vector<vector<int>> dp(s.size()+1,vector<int>(2,0));
        int n =s.size();
        int z=0,o=0;
        for(int i=1;i<=n;i++){
            
            if(s[i-1]=='0'){
                z++;
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][0] + 1;
            }
            else{
                o++;
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = dp[i-1][0];
            }
        }
        if(abs(o-z)>1)
            return -1;
        if(dp[n][0]%2 ==0){
            if(dp[n][1]%2==1)
                return dp[n][0]/2;
            else
                return min(dp[n][0],dp[n][1])/2;
        }
        if(dp[n][0]%2 ==1){
            if(dp[n][1]%2==0)
                return dp[n][1]/2;
            else
                return min(dp[n][0],dp[n][1])/2;
        }
        return 0;
        
    }
};

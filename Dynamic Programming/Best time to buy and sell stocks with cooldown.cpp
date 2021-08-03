/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

----------------------------------------------------------------------------------
----------------------------------------------------------------------------------*/

int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[n][3];
        for(int i=0;i<n;++i){
            if(i==0)
            {
                dp[i][0]=-prices[i]; //This is the cost when stock i is bought
                dp[i][1]=0;      //idle value(i.e neither sold nor bought)
                dp[i][2]=0;   //when this stock was sold
            }
            else{
                dp[i][0]=dp[i-1][1]-prices[i];  //we can but only when prvious state is ideal
                dp[i][0]=max(dp[i][0],dp[i-1][0]);
                dp[i][1]=max(dp[i-1][2],dp[i-1][1]);
                dp[i][2]=prices[i]+dp[i-1][0];   //can sell only when previous was bought
                
            }
            
        }
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}); //return maximum of all state
        
    }

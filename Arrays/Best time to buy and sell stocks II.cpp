/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tempmin = INT_MAX,min=prices[0],profit=0,n=prices.size();
        for(int i=0;i<n;i++)
            if(prices[i]<tempmin)  tempmin = prices[i];
            else if(i<n-1 && prices[i+1]<prices[i] || i==n-1 && tempmin<prices[i]){
                profit += prices[i]-tempmin;
                tempmin = INT_MAX;
            }
        return profit;
    }
};

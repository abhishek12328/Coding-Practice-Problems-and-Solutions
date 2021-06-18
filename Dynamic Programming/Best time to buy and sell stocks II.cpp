/*Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

----------------------------------------------------
---------------------------------------------------*/


int Solution::maxProfit(const vector<int> &a) {
    int n = a.size(),start=0,ans = 0;
    for(int i=0;i<n;i++){
        if(a[i] > a[start]){
            ans += a[i]-a[start];
            start = i;
        }
        if(a[i]<a[start]){
            start = i;
        }
    }
    return ans;
}

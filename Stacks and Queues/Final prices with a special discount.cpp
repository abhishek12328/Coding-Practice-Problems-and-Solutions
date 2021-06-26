/*Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.

 ----------------------------------------------------
 ----------------------------------------------------*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> nse=prices;
        
        stack<int> s;
        
        
        for(int i=0;i<n;i++){
            
            while(!s.empty()&& prices[i]<= prices[s.top()]){
                nse[s.top()]=prices[s.top()]-prices[i];
                s.pop();
            }
            s.push(i);
        }
        
        for(int i=0;i<n;i++)
            cout<<nse[i]<<" ";
        return nse;
    }
};

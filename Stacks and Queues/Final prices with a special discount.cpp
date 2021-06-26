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

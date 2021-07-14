/*In LeetCode Store, there are n items to sell. Each item has a price. However, there are some special offers, and a special offer consists of one or more different kinds of items with a sale price.

You are given an integer array price where price[i] is the price of the ith item, and an integer array needs where needs[i] is the number of pieces of the ith item you want to buy.

You are also given an array special where special[i] is of size n + 1 where special[i][j] is the number of pieces of the jth item in the ith offer and special[i][n] (i.e., the last integer in the array) is the price of the ith offer.

Return the lowest price you have to pay for exactly certain items as given, where you could make optimal use of the special offers. You are not allowed to buy more items than you want, even if that would lower the overall price. You could use any of the special offers as many times as you want.

 ---------------------------------------------------
 ----------------------------------------------------*/

class Solution {
public:
    map<vector<int>,int> mp;
    int solve(vector<int>&p,vector<vector<int>>& s,vector<int>& n){
        
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        int a=s.size();
        int ans=0;
        for(int i=0;i<n.size();i++){
            ans = ans+n[i]*p[i];
        }
        for(int i=0;i<a;i++){
            int m = s[i].size();
            bool flag = true;
            for(int j=0;j<m-1;j++){
                if(n[j]<s[i][j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                int z = s[i].size();
                int price = s[i][z-1];
                for(int k=0;k<n.size();k++){
                    n[k] = n[k]-s[i][k];
                }
                int x = price+solve(p,s,n);
                ans = min(ans,x);
                for(int k=0;k<n.size();k++){
                    n[k] = n[k]+s[i][k];
                }
            }
        }
        
        return mp[n]=ans;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price,special,needs);   
    }
};

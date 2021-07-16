/*There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


-----------------------------------------------------
-----------------------------------------------------*/


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> g(n,0);
        vector<int> l(n,0);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
            if(rating[i]<rating[j]){
                g[i]++;
            }
            }
        }
        int ans =0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
            if(rating[i]<rating[j]){
                ans = ans + g[j];
            }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
            if(rating[i]>rating[j]){
                l[i]++;
            }
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
            if(rating[i]>rating[j]){
                ans = ans + l[j];
            }
            }
        }
        return ans;
        
    }
};

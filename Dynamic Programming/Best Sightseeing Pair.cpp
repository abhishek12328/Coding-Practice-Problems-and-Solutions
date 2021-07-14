/*You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

-------------------------------------------------------------------
-------------------------------------------------------------------*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> add(n);
        vector<int> subtract(n);
        vector<int> maximum(n);
        for(int i=0;i<n;i++){
            add[i] = values[i]+i;
        }
        maximum[0] = add[0];
        for(int i=1;i<n;i++){
            maximum[i] = max(maximum[i-1],add[i]); 
        }
        for(int i=0;i<n;i++){
            subtract[i] = values[i]-i;
        }
        int ans=INT_MIN;
        for(int i = n-1;i>=1;i--){
            if(ans< subtract[i]+maximum[i-1])
                ans = subtract[i]+maximum[i-1];
        }
        return ans;
    }
};

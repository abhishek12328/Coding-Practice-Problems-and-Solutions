/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int begin=intervals[0][0],end = intervals[0][1];
        vector<vector<int>> v;
        for(int i=0;i<n-1;i++){
            if(end<intervals[i+1][0]){
                v.push_back({begin,end}); 
                begin = intervals[i+1][0];
                end = intervals[i+1][1];
            }
            else if(end>=intervals[i+1][0]){
                end = max(end,intervals[i+1][1]);
            }
        }
        v.push_back({begin,end});
        return v;
        
    }
};

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

//java

class Solution {
    public int[][] merge(int[][] intervals) {
        if(intervals.length == 1 )
        return intervals; 
        int n = intervals.length;
        ArrayList<int[]> ans = new ArrayList<>();

        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]-b[0];
            }
        });
        int i=0,j=1;
        while(i<n){
            int max = intervals[i][1];
            while(j<n && max>=intervals[j][0]){
                if(max < intervals[j][1]) max = intervals[j][1];
                j++;
            }
            ans.add(new int[]{intervals[i][0],max});
            i=j;
            j++;
        }
        return ans.toArray(new int[ans.size()][]);
    }
}

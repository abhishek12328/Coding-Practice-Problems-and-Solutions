/*You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.

Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.

We can cut these clips into segments freely.

For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.

 ---------------------------------------------------------
 ---------------------------------------------------------*/


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int t) {
        int n= clips.size();
        sort(clips.begin(),clips.end());
        if(clips[0][0]!=0)
            return -1;
        vector<int> dp(n,INT_MAX-1000);
        
        for(int i=0;i<n;i++){
            int ans = INT_MAX-1000;
            for(int j=0;j<i;j++){
                if(clips[i][0]<=clips[j][1])
                    ans = min(ans,dp[j]+1);
            }
            dp[i] = ans;
            if(clips[i][0] == 0)
                dp[i] = 1;
            if(clips[i][1]>=t && dp[i]!=INT_MAX-1000)
                return dp[i];
        }
        return -1;
    }
    
  
};

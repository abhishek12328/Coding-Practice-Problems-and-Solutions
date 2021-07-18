/*The minimum absolute difference of an array a is defined as the minimum value of |a[i] - a[j]|, where 0 <= i < j < a.length and a[i] != a[j]. If all elements of a are the same, the minimum absolute difference is -1.

For example, the minimum absolute difference of the array [5,2,3,7,2] is |2 - 3| = 1. Note that it is not 0 because a[i] and a[j] must be different.
You are given an integer array nums and the array queries where queries[i] = [li, ri]. For each query i, compute the minimum absolute difference of the subarray nums[li...ri] containing the elements of nums between the 0-based indices li and ri (inclusive).

Return an array ans where ans[i] is the answer to the ith query.

A subarray is a contiguous sequence of elements in an array.

The value of |x| is defined as:

x if x >= 0.
-x if x < 0.*/

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>>v;
        vector<int>ans;
        
        
        vector<int>temp(101,0);
        v.push_back(temp);
        
        for(auto x:nums)
        {
            vector<int>temp=v[v.size()-1];
            temp[x]++;
            v.push_back(temp);
        }
        
        for(auto x:queries)
        {
            vector<int>a=v[x[0]];
            vector<int>b=v[x[1]+1];
           
            for(int i=0;i<b.size();i++)
            {
                b[i]-=a[i];
            }
            
            int prev=-1,ans1=INT_MAX;
             for(int i=0;i<b.size();i++)
            {
              if(b[i]>0&&prev==-1)
                  prev=i;
              else if(b[i]>0)
              {
                  ans1=min(ans1,i-prev);
                  prev=i;
              }  
             }
            if(ans1==INT_MAX)
                ans1=-1;
            
            ans.push_back(ans1);
        }
        return ans;
    }
};

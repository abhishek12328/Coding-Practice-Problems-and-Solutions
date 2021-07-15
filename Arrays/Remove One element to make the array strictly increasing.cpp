/*Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.

The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

 ---------------------------------------------------------
 ---------------------------------------------------------*/

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        stack<int> st;
        st.push(nums[0]);
        int n = nums.size(),count=0;
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[i]<=st.top()){
                st.pop();
                count++;
            }
            st.push(nums[i]);
        }
        if(count==0 || count == 1)
            return 1;
        while(!st.empty())
        st.pop();
        
        st.push(nums[0]);
        count = 0;
        
        for(int i=1;i<n;i++){
            if(!st.empty() && nums[i]<=st.top()){
                count++;
            }
            else
            st.push(nums[i]);
        }
        return (count==0||count==1)?1:0;
        
        
    }
};

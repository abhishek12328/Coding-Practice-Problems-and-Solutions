/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> v;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int start = j+1, end = nums.size()-1;
                long newtarget;
                newtarget = 1l*target-1l*nums[i]-1l*nums[j];
                while(start<end){
                    if(1l*nums[start]+1l*nums[end] > newtarget){
                        end--;
                    }
                    else if(1l*nums[start]+1l*nums[end] < newtarget){
                        start++;
                    }
                    else{
                        v.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                }

            }
        }
        vector<vector<int>> ans;
        for(auto temp:v){
            ans.push_back(temp);
        }
        return ans;
        
    }
};

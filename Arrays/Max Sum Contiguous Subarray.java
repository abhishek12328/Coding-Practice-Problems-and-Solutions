/*Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

class Solution {
    public int maxSubArray(int[] nums) {
        int maxsum=nums[0], tempsum = nums[0], start =0;
        for(int i=1;i<nums.length;i++){
            if(tempsum < 0)
            tempsum =0;
            tempsum = tempsum+nums[i];
            if(maxsum < tempsum)
            maxsum = tempsum;
        }
        return maxsum;
    }
}

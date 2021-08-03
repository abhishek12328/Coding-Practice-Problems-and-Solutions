/*The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 --------------------------------------------------------
 --------------------------------------------------------*/

class Solution {
public:
    
    void solve(vector<int> nums, int ind,int x,int& ans){
        if(ind == nums.size()){
            ans = ans + x;
            return;
        }    
        for(int i=ind;i<nums.size();i++){
            x = x ^ nums[i];
            solve(nums,i+1,x,ans);
            x = x ^ nums[i];
        }
        solve(nums,nums.size(),x,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        
        int ans=0;
        solve(nums,0,0,ans);
        return ans;
    }
};

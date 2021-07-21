/*Given an integer array nums, your goal is to make all elements in nums equal. To complete one operation, follow these steps:

Find the largest value in nums. Let its index be i (0-indexed) and its value be largest. If there are multiple elements with the largest value, pick the smallest i.
Find the next largest value in nums strictly smaller than largest. Let its value be nextLargest.
Reduce nums[i] to nextLargest.
Return the number of operations to make all elements in nums equal.

-----------------------------------------------------------------*/


class Solution {
public:
    int reductionOperations(vector<int>& nums) {        
        map<int,int> m;
        
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        } 
        int i=0,ans=0;
        for(auto j:m ){
            ans = ans + j.second*i;
            i++;
        }
        return ans;
    }
};

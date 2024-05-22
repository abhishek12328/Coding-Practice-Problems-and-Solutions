/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/


class Solution {
public:

    int merge(vector<int>& nums, int start, int middle, int end){
        if(start ==0 && end == 4){
            for(int i=0;i<5;i++)
            cout << nums[i];
        }
        vector<int> temp(end-start+1);
        int i=start, j=middle+1, k=0;
        int ans = 0;
        while(i<=middle && j<=end){
            if(1L*nums[i] > 1L*2*nums[j] ){
                ans += middle-i+1;
                j++;
            }
            else{
                i++;
            }
        }
        i=start, j = middle+1;
        while(i<=middle && j<=end){
            if(nums[i]<nums[j]){
                temp[k] = nums[i];
                i++;
            }
            else{
                temp[k] = nums[j];
                j++;
            }
            k++;
        }
        while(i<=middle){
            temp[k] = nums[i];
            i++; k++;
        }
        while(j<=end){
            temp[k] = nums[j];
            j++; k++;
        }
        for( i=0;i<temp.size();i++){
            nums[start+i] = temp[i];
        }
        return ans;
    }

    int mergesort(vector<int>& nums, int start, int end){
        if(start>=end){
            return 0;
        }
        int ans=0,middle;
        middle = start+(end-start)/2;
        ans += mergesort(nums, start, middle);
        ans += mergesort(nums, middle+1, end);
        ans += merge(nums, start, middle, end);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size()-1);
    }
};  

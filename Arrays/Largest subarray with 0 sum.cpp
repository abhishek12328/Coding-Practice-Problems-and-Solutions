/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i


*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        int ans = 0, tempsum=0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i=0;i<A.size();i++){
            tempsum += A[i];
            if(mp.count(tempsum) > 0 && i-mp[tempsum] > ans){
                ans =  i-mp[tempsum];
            }
            else if(mp.count(tempsum) == 0)
            mp[tempsum] = i;
        }
        return ans;
        // Your code here
    }
};

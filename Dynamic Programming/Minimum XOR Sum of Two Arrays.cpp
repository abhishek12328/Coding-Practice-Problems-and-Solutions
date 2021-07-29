/*You are given two integer arrays nums1 and nums2 of length n.

The XOR sum of the two integer arrays is (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) (0-indexed).

For example, the XOR sum of [1,2,3] and [3,2,1] is equal to (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4.
Rearrange the elements of nums2 such that the resulting XOR sum is minimized.

Return the XOR sum after the rearrangement.


-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------*/


class Solution {
public:
    
    bool isvalid(int a,int b){
        return a &(1<<b);
    }
    
    void make_invalid(int&a,int b){
        a =  a ^ (1<<b);
    }
    
    int solve(vector<vector<int>>& dp,vector<int> nums1,vector<int> nums2,int one,int two){
        if(dp[one][two]!=-1)
            return dp[one][two];
        int maxor =INT_MAX;
  
                for(int j=0;j<nums2.size();j++){
                    if(isvalid(two,j)){
                        make_invalid(two,j);
                        if((one-1)>=0)
                        maxor = min(maxor,(nums1[one]^nums2[j])+solve(dp,nums1,nums2,one-1,two)); 
                        else
                            maxor = (nums1[one]^nums2[j]);
                        make_invalid(two,j);
                    }
                }
               
        return dp[one][two] = maxor;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int one = nums1.size()-1,two = pow(2,nums2.size())-1;
        vector<vector<int>> dp(one+1,vector<int>(two+1,-1));
        dp[0][0] = 0;
        return solve(dp,nums1,nums2,one,two);
    }
};

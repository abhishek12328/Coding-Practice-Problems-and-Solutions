/*You are given an integer array nums. The adjacent integers in nums will perform the float division.

For example, for nums = [2,3,4], we will evaluate the expression "2/3/4".
However, you can add any number of parenthesis at any position to change the priority of operations. You want to add these parentheses such the value of the expression after the evaluation is maximum.

Return the corresponding expression that has the maximum value in string format.

Note: your expression should not contain redundant parenthesis.

*/


class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        string ans;
		
		// check for size if its 1 then we can't use parantheses and 
		// if its 2 then also we should not use it.
		
        if(n==1) return ans=to_string(nums[0]);
        if(n==2) return ans=to_string(nums[0])+"/"+to_string(nums[1]);
		
		//  for size greater than 2 add paranthese after first number 
		
        ans=to_string(nums[0]);
        ans.append("/(");
        for(int i=1;i<n-1;i++){
            ans.append(to_string(nums[i])+"/");
        }
        ans.append(to_string(nums[n-1]));
        ans.append(")");
		
		// finally this becomes as a/(b/c/d/....) which is our answer
		
        return ans;
    }
};

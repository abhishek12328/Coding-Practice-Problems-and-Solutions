/*Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.

Build the target array using the following operations:

Push: Read a new element from the beginning list, and push it in the array.
Pop: delete the last element of the array.
If the target array is already built, stop reading more elements.
Return the operations to build the target array. You are guaranteed that the answer is unique.

 ----------------------------------------------------
 ----------------------------------------------------*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int m) {
        int n =target.size(),i;
        vector<string> ans;
        for(i=1;i<=target[n-1] && i<=m;i++){
            if(find(target.begin(),target.end(),i)!=target.end()){
                ans.push_back("Push");
            }            
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};

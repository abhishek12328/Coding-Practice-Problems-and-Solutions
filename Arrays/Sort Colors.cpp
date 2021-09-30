/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(auto k:nums) {
            if(k==0) r++;
            if(k==1) w++;
            if(k==2) b++;
        }
        int i=0;
        while(r--){
           nums[i] = 0;
            i++;
        } 
        while(w--){
           nums[i] = 1;
            i++;
        } 
        while(b--){
           nums[i] = 2;
            i++;
        } 
      
    }
};

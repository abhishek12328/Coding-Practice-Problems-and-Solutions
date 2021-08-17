/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

*/


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i=1,len=1,n=nums.size(),ans=1;
        long long int temp=0;
        sort(begin(nums),end(nums));
        vector<int> v;
        v.push_back(0);
        for(int i=1;i<n;i++) v.push_back(nums[i]-nums[i-1]);
        vector<long long int> sum(n);
        sum[0]= 0;
        for(int i=1;i<n;i++) sum[i] = sum[i-1]+v[i];
        i=1;
        while(i<n){
            if(temp+1LL*len*(nums[i]-nums[i-1])<=k){
                temp +=  len*(nums[i]-nums[i-1]);
                len++;
                i++;
            }
            else{
                temp -= sum[i-1]-sum[i-len];
                len--;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};

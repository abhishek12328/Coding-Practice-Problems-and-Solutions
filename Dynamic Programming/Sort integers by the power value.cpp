/*The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the k-th integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in 32 bit signed integer.

-----------------------------------------------------------------
-----------------------------------------------------------------*/


class Solution {
public:
    unordered_map<int, int>mp;
    void precompute(){
        mp[1] = 0;
        mp[2] = 1;
        mp[3] = 7;
    }
    
    // this is the function which uses memoization.
    int solve(int n){
        if(mp.find(n) == mp.end()){
            if(!(n&1)){
                mp[n] = solve(n/2)+1;
            }else{
                // okay so we need to solve for the value 3*x + 1;
                mp[n] = solve(3*n+1) + 1;
            }
        }
        return mp[n];
    }
    int getKth(int lo, int hi, int k) {
        precompute();
        vector<pair<int, int>>arr(hi-lo+1);
        for(int i = 0; i<(int)arr.size(); i++){
            arr[i]  = {solve(i+lo), i+lo};
        }
        sort(arr.begin(), arr.end());
        return arr[k-1].second;
    }
};

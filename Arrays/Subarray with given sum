/* Given an unsorted array A of size N that contains only positive integers, find a continuous sub-array that adds to a given number S and return the left and right index(1-based indexing) of that subarray.

In case of multiple subarrays, return the subarray indexes which come first on moving from left to right.

Note:- You have to return an ArrayList consisting of two elements left and right. In case no such subarray exists return an array consisting of element -1.

*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int tempsum=0,start=0,end;
        for(int i=0;i<n;i++){
            tempsum += arr[i];
            end = i;
            if(tempsum == s)
                return {start+1,end+1};
            else if(tempsum > s){
                for(int j=start;j<=end;j++){
                    tempsum -= arr[j];
                    start += 1;
                    if(start>end)
                        break;
                    else if(tempsum == s)
                        return {start+1,end+1};
                    else if(tempsum < s)
                        break;
                }
            }
        }
        return {-1};
    }
};

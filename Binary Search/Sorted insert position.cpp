/*Given a sorted array A and a target value B, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

-----------------------------------------------------------------
-----------------------------------------------------------------*/


int Solution::searchInsert(vector<int> &a, int b) {
    int n = a.size(),start = 0,end = n,mid;
    while(start<=end){
        mid = (start+end)/2;
        if(a[mid] == b)
        return mid;
        else if(a[mid] < b){
            if(mid == n-1 || a[mid+1] > b)
            return mid + 1;
            else
            start = mid +1;
        }
        else{
            if(mid == 0 || a[mid -1 ]<b)
            return mid;
            else
            end = mid -1;
        } 
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

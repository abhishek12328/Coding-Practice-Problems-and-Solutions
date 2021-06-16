/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle

------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------
------------------------------------------------------------*/



int Solution::minimumTotal(vector<vector<int> > &a) {
    int n =a.size(),i,j;
    vector<int> v(n+1,INT_MAX);
    v[1] = a[0][0];
    for(i=2;i<=n;i++){
        for(j=i;j>=1;j--){
            v[j] = a[i-1][j-1] + min(v[j],v[j-1]);
        }
    }
    int ans = INT_MAX;
    for(i=1;i<=n;i++){
    if(ans > v[i]){
    ans = v[i];
    }
    }
    
    return ans;
    
    
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

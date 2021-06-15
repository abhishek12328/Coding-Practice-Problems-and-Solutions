/*Given a N * 2 array A where (A[i][0], A[i][1]) represents the ith pair.

In every pair, the first number is always smaller than the second number.

A pair (c, d) can follow another pair (a, b) if b < c , similarly in this way a chain of pairs can be formed.

Find the length of the longest chain subsequence which can be formed from a given set of pairs.

------------------------------------
------------------------------------
------------------------------------
------------------------------------*/

int Solution::solve(vector<vector<int> > &a) {
    int n=a.size(),max = 0,ans = INT_MIN;
    vector<int> v(n,1);
    for(int i=n-1;i>=0;i--){
        max = 0;
        for(int j=i+1;j<n;j++){
            if(a[i][1]<a[j][0] && v[j]>max)
            max = v[j];
        }
        v[i] = 1+max;
        if(ans < v[i])
        ans = v[i];
    }
    return ans;
}

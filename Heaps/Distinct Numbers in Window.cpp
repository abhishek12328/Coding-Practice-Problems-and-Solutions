/*You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE: if B > N, return an empty array.

-------------------------------------------------
-------------------------------------------------*/

vector<int> Solution::dNums(vector<int> &a, int b) {
    int n = a.size();
    map<int,int> m;
    vector<int> ans(n-b+1,0);
    for(int i=0;i<b;i++){
        if(m[a[i]] == 0)
        ans[0]++;
        m[a[i]]++;
    }
    for(int i=b;i<n;i++){
        if(m[a[i-b]] == 1)
        ans[i-b+1] = -1;
        m[a[i-b]]--;
        if(m[a[i]] == 0)
        ans[i-b+1] += ans[i-b] + 1;
        else
        ans[i-b+1] += ans[i-b];
        m[a[i]]++;
    }
    return ans;
}

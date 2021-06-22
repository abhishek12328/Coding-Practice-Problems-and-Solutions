/*Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.

----------------------------------------------
----------------------------------------------*/



int Solution::longestSubsequenceLength(const vector<int> &a) {
    
    int n = a.size(),ans =0,i,j;
    if(n==0)
    return 0;
        vector<int> inc(n,0);
        vector<int> dec(n,0);
        for(i=0;i<n;i++){
            int max = 0;
            for(j=i-1;j>=0;j--)
                if(a[i]>a[j] && max<inc[j])  max = inc[j];
            inc[i] = max+1;
        }
        for(i=n-1;i>=0;i--){
            int max = 0;
            for(j=i+1;j<n;j++)
                if(a[i]>a[j] && max<dec[j])  max = dec[j];
            dec[i] = max+1;
            if(ans < inc[i]+dec[i])
            ans = inc[i]+dec[i];
        }
        return ans-1;
        
        
}

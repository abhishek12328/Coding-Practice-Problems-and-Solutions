

vector<int> Solution::flip(string a) {
    int i,j,n=a.size(),max = 0,count=0,flag = 0,old;
    vector<int> ans(2,1);
    
    vector<int> b(n,0);
    for(i=0;i<n;i++){
        if(a[i]=='0')
        b[i] = 1;
        if(a[i]=='1')
        
    b[i] = -1; 
    }
    vector<int> dp(n+1,0);

    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + b[i];
        if(b[i]>0)
        flag = 1;
        
        if (max_so_far < max_ending_here){
            ans[1] = i+1; 
            max_so_far = max_ending_here;
        }
 
        if (max_ending_here < 0){
            max_ending_here = 0;
            if(i+1 < n){
            if(ans[0]<=ans[1])
            old = ans[0];
            ans[0] = i+2;
            }
        }
    }
    vector<int> ab;
    if (flag == 0)
    return ab;
    if(ans[0]>ans[1])
    ans[0] = old;
    return ans;
}

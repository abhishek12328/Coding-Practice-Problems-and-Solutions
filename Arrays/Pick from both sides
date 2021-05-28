int Solution::solve(vector<int> &a, int b) {
    vector<int> sum;
    int i;
    sum.push_back(a[0]);
    for(i=1;i<a.size();i++){
        sum.push_back(sum[i-1]+a[i]);
    }
    int maximum = sum[a.size()-1] - sum[a.size()-1-b];
    for(i=1;i<=b;i++){
        maximum = max(maximum,sum[i-1]+sum[a.size()-1]-sum[a.size()-1-(b-i)]);
    }
    return maximum;
}

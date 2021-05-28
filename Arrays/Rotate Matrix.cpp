int Solution::solve(vector<int> &a) {
    sort(a.begin(),a.end());
    if(a[a.size()-1]==0)
    return 1;
    for(int i=0;i<a.size();i++){
        if(i<a.size()-1 && a[i]!=a[i+1] && a[i] == a.size()-i-1){
            return 1;
        }
        
    }
    return -1;
}

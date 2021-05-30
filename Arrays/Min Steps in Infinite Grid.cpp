int no_of_steps(int x1, int x2, int y1, int y2){
    if(abs(x1-x2)>=abs(y1-y2))
    return abs(x1-x2);
    else
    return abs(y1-y2);
}
int Solution::coverPoints(vector<int> &a, vector<int> &b) {
    int i,count=0,n=a.size();
    for(i=0;i<n-1;i++){
        count+=no_of_steps(a[i],a[i+1],b[i],b[i+1]);    
    }
    return count;
}

int Solution::maxSubArray(const vector<int> &a) {
    int i,max=0,flag = 0,tempmax = 0,n=a.size(),negmax = -99999999;
    for(i=0;i<n;i++){
        if(a[i]>=0){
        flag = 1;
        
        }
        if(negmax<a[i] && a[i]<0)
        negmax = a[i];
        tempmax = tempmax + a[i];
        if(tempmax>max)
        max = tempmax;
        if(tempmax<0)
        tempmax = 0;
    }
    
    return (flag==0)?negmax:max;
}

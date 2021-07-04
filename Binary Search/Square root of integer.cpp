int Solution::sqrt(int A) {
    if(A==0 || A==1)return A;
    int low=0,high=A/2;
    int res=0;
    while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid==A){
            return mid;
        }else if(mid*mid<A){
            res=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return res;
}

int Solution::firstMissingPositive(vector<int> &A) {
    int temp,i,n=A.size(),temp1,it;
    
    for(i=0;i<n;i++){
        if(1<=A[i] && A[i]<=n && A[i] != -1000){
            it = A[i]-1;
            while(1){
                temp1 = A[it];
                A[it] = -1000;
                if(1<=temp1 && temp1<=n){
                    it = temp1-1;
                }
                else
                break;
                if(it == i){
                    A[it] = -1000;
                    break;
                }
            }
            
        }
    }
    for(i=0;i<n;i++){
        cout << A[i] << " ";
        if(A[i]!=-1000)
        return i+1;
    }
    return n+1;
}

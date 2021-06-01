void Solution::rotate(vector<vector<int> > &A) {
    
    int i,j,temp,n = A.size(),k,newi,newj;
    for(i=0;i<(A.size())/2;i++){
        for(j=i;j<n-i-1;j++){
            temp = A[i][j];
            for(k=1;k<=4;k++){
            newi = j;
            newj = A.size()-1-i;
            int temp1 = A[newi][newj];
            A[newi][newj] = temp;
            temp = temp1;
            i = newi;
            j = newj;
            }
        }
    } 
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

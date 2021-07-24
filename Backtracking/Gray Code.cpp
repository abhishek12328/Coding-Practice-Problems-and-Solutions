/*The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.


-------------------------------------------------------------------------
-------------------------------------------------------------------------*/



vector<int> Solution::grayCode(int a) {
    
    if(a==1)
    return {0,1};
    
    vector<int> tans = grayCode(a-1);
    
    for(int i=tans.size()-1;i>=0;i--){
        tans.push_back(pow(2,a-1)+tans[i]);
        
    }
    return tans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

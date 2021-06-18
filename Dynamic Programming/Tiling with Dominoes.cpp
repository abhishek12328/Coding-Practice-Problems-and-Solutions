/*Given an integer A you have to find the number of ways to fill a 3 x A board with 2 x 1 dominoes.

Return the answer modulo 109 + 7 .

NOTE:

See the sample explanation for better understanding.

----------------------------------------------
----------------------------------------------*/

int Solution::solve(int a) {
    if(a==1)
    return 0;
    vector<int> t(a,-1);
    vector<int> r(a,-1);
    vector<int> c(a,-1);
    c[0] = 0;
    c[1] = 3;
    t[0] = 1;
    r[0] = 1;
    t[1] = 0;
    r[1] = 0;
    for(int i=2;i<a;i++){
        c[i] = ((t[i-1]+r[i-1])%1000000007+c[i-2])%1000000007;
        t[i] = (c[i-1] + t[i-2])%1000000007;
        r[i] = (c[i-1] + r[i-2])%1000000007;
    } 
    return c[a-1];
}

/*Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.

Find the maximum number of chocolates that kid can eat in A units of time.

NOTE:

floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7

--------------------------------------------------------
--------------------------------------------------------*/

int Solution::nchoc(int a, vector<int> &b) {
    int ans=0,n = b.size(),i;
    int m = 1000000007;
    priority_queue<int> pq;
    for(i=0;i<n;i++)
    pq.push(b[i]);
    for(i=0;i<a;i++){
        int temp = pq.top();
        ans = (ans + temp%m)%m;
        pq.pop();
        pq.push(temp/2);
    }
    return ans;
}

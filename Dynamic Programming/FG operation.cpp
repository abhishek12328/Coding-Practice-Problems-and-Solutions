/*We have a sequence of N integers between 0 and 9 (inclusive): A=(A1,…,AN), arranged from left to right in this order.

Until the length of the sequence becomes 1, we will repeatedly do the operation F or G below.

Operation F: delete the leftmost two values (let us call them x and y) and then insert (x+y)%10 to the left end.
Operation G: delete the leftmost two values (let us call them x and y) and then insert (x×y)%10 to the left end.
Here, a%b denotes the remainder when a is divided by b.

For each K=0,1,…,9, answer the following question.

Among the 2^N−1 possible ways in which we do the operations, how many end up with K being the final value of the sequence?
Since the answer can be enormous, find it modulo 998244353.*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<vector<int>> dp(n,vector<int>(10,0));
    dp[0][v[0]] = 1;
    map<pair<int,int>,vector<int>> m;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            m[{i,(i*j)%10}].push_back(j); 
            m[{i,(i+j)%10}].push_back(j);
        }
    }
    
    
    for(int i=1;i<n;i++){
        for(int j=0;j<10;j++){
            for(auto k:m[{v[i],j}]){
                dp[i][j] = dp[i][j] + dp[i-1][k];  
                dp[i][j] %= 998244353;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout << dp[n-1][i] << endl;
    }
}

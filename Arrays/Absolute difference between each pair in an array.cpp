#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++) cin>> v[i];
    sort(v.begin(),v.end());
    vector<int> sum(n);
    sum[0] = v[0];
    int ans = 0;
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1]+v[i]; 
        ans += (v[i]*i - sum[i-1]);
    }
    std::cout << ans << std::endl;
    
}

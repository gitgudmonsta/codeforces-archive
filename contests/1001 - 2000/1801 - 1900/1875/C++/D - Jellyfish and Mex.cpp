#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.
 
using i64 = long long;

int n;
int cnt[5001];
int  dp[5001];

void solve() {
    std::cin >> n;
    memset(cnt, 0, 5001);
    memset(dp, -1, 5001);
    
    for(int i = 0; i < n; i++) {
        int t; std::cin >> t;
        if(t <= 5000) ++cnt[t];
    }
    
    int mex = 0; while(cnt[mex] > 0) mex++;
    
    for(int i = mex; i >= 0; i--) {
        if(cnt[i] != 0)
            for(int j = i + 1; j <= mex; j++)
                dp[i] = (dp[i] == -1)? dp[j] + (cnt[i] - 1) * j + i: 
                                       std::min(dp[i], dp[j] + (cnt[i] - 1) * j + i);
        // back to front
        
        else dp[i] = 0;
    }
    
    std::cout << dp[0] << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    int tst; std::cin >> tst;
    while(tst--)
        solve();
        
    return 0;
}
 
// g++ -std=c++20 <filename>.cpp

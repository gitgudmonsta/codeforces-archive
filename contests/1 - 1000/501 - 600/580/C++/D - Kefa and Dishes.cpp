#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

void solve() {
    int n, m, k; 
    std::cin >> n >> m >> k;
    
    std::vector<int> a(n);
    std::vector<std::vector<int>> satis(n, std::vector<int>(n, 0));
    
    for(int& i: a)
        std::cin >> i;
    for(int i = 0; i < k; i++) {
        int x, y, c;
        std::cin >> x >> y >> c;
        satis[--x][--y] = c;
    }
    
    std::vector<std::vector<i64>> dp(1 << n, std::vector<i64>(n, 0));
    
    for(int mask = (1 << n) - 1; ~mask; --mask) {
        if(__builtin_popcount(mask) >= m) continue;
        
        for(int prev = 0; prev < n; ++prev) {
            if(!((1 << prev) & mask)) continue;   // continue if prev not consumed already
                                                  // calculate if prev is consumed
            dp[mask][prev] = 0;
            for(int i = 0; i < n; i++) {
                if(!((1 << i) & mask)) {          // calculate if i not consumed already
                    dp[mask][prev] = 
                    std::max(dp[mask][prev], dp[mask | (1 << i)][i] + a[i] + satis[prev][i]);
                }
            }
        }
    }
    
    i64 ans = 0;
    for(int i = 0; i < n; i++)
        ans = std::max(ans, a[i] + dp[1 << i][i]);
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);std::cout.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    
    solve();
    
    return 0;
}

// g++ -std=c++20 <filename>.cpp

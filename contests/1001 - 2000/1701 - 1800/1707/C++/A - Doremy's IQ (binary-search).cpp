#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int n, iq;
int a[100001];
int b[100001];

bool check(int mid, int q) {
    memset(b, 0, sizeof b);
    
    for(int i = 1; i < mid; i++)
        b[i] = (a[i] <= q)? 1: 0;
    
    int idx = mid;
    while(idx != n + 1) {
        if(q == 0)
            return false;
        if(a[idx] > q) --q;
        b[idx] = 1;
        ++idx;
    }
    
    return true;
}

void solve() {
    std::cin >> n >> iq;
    
    for(int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    int x = n + 1;
    
    int l = 1, r = n + 1;
    while(l < r) {
        int mid = l + (r - l)/2;
        
        if(check(mid, iq)) {
            x = std::min(x, mid);
            r = mid;
        }
        else l = mid + 1;
    }
    check(x, iq);
    
    for(int i = 1; i <= n; i++)
        std::cout << b[i];
    std::cout << '\n';
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

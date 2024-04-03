#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int n, iq;
int a[100001];
int b[100001];

void solve() {
    std::cin >> n >> iq;
    
    for(int i = 1; i <= n; i++)
        std::cin >> a[i];
    
    int tq = 0;
    for(int i = n; i > 0; i--) {
        if(a[i] <= tq) b[i] = 1;
        else if(a[i] > tq && tq < iq) {
            b[i] = 1; ++tq;
        }
        else b[i] = 0;
    }
    
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

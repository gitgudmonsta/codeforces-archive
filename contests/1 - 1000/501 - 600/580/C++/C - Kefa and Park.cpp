#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

std::vector<int> cats;
std::vector<std::vector<int>> tree;
int n, m, ans = 0;

void dfs(int curr, int prev, int cs) {
    if(curr != 0 && (int)tree[curr].size() == 1 && cs <= m)
        ++ans;
    
    for(int next: tree[curr]) {
        if(next != prev) {
            if(cs + cats[next] <= m)
                dfs(next, curr, (cats[next] == 0)? 0: cs + 1);
        }
    }
}

void solve() {
    std::cin >> n >> m;
    
    cats.resize(n); tree.resize(n);
    
    for(int& i: cats) 
        std::cin >> i;
    for(int i = 0; i < n -1; i++) {
        int x, y;
        std::cin >> x >> y;
        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }
    
    dfs(0, -1, cats[0]);
    std::cout << ans << '\n';
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

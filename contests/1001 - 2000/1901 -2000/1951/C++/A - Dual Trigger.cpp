#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.
 
using i64 = long long;

int n;
std::string s;

std::string solve() {
    std::cin >> n; std::cin >> s;
    
    std::vector<int> v;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1')
            v.push_back(i);
    }
    
    if((int)v.size() == 2) 
        return (v[1] - v[0] == 1)? "NO": "YES";
    
    if((int)v.size() & 1) return "NO";
    
    return "YES";
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
        std::cout << solve() << '\n';
    
    return 0;
}

// g++ -std=c++20 <filename>.cpp

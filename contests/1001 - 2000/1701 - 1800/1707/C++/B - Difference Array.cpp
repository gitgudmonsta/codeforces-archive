#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> //.

using i64 = long long;

int n, cnt_zero;
int arr[100001];
std::priority_queue<int, std::vector<int>, std::greater<int>> non_zero;

void compute() {
    if(non_zero.empty()) {
        cnt_zero = std::max(0, cnt_zero - 1);
        return;
    }
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> temp;
    
    int x1 = non_zero.top();
    non_zero.pop();
    
    if(cnt_zero) temp.push(x1);
    cnt_zero = std::max(0, cnt_zero - 1);
    
    while(!non_zero.empty()) {
        int x2 = non_zero.top();
        int d = x2 - x1;
        
        if(d == 0) ++cnt_zero;
        else temp.push(d);
        x1 = x2;
        non_zero.pop();
    }
    
    non_zero = temp;
}

void solve() {
    std::cin >> n;
    
    for(int i = 0; i < n; i++) std::cin >> arr[i];
    
    cnt_zero = 0; 
    non_zero = std::priority_queue<int, std::vector<int>, std::greater<int>>();
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) non_zero.push(arr[i]);
        else ++cnt_zero; 
    }
    
    for(int i = 1; i <= n - 1; i++) {
        compute();
        if(non_zero.empty()) break;
    }
    
    if(non_zero.empty()) std::cout << 0;
    else std::cout << non_zero.top();
    
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

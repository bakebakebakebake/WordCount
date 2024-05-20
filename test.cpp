#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve() {
    int n;cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);g[v].push_back(u);
    }
    vector<int>c(n + 1);
    for (int i = 1;i <= n;i++)cin >> c[i];
    vector<ll> sum(n + 1);
    auto dfs1 = [&](auto self, int x, int p) -> void {
        sum[x] = c[x];
        for (auto y : g[x]) {
            if (y == p)continue;
            self(self, y, x);
            sum[x] += sum[y];
        }
        };
    dfs1(dfs1, 1, 0);

    auto dfs2 = [&](auto self, int x, int p) -> int {
        for (auto y : g[x]) {
            if (y == p || 2 * sum[y] <= sum[1])continue;
            return self(self, y, x);
        }
        return x;
        };
    int x = dfs2(dfs2, 1, 0);
    dfs1(dfs1, x, 0);
    ll ans = 0;
    for (int i = 1;i <= n;i++) {
        if (i != x)ans += sum[i];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
    solve();
}

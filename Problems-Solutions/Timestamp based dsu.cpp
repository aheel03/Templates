// https://codeforces.com/gym/106689/problem/G
#include <bits/stdc++.h>
using namespace std;

const int MAXW = 1000000;

struct DSU {
    vector<int> par, sz, seen;
    int timer = 0;
    int merges = 0;

    DSU(int n) : par(n + 1),
                 sz(n + 1),
                 seen(n + 1, 0) {}

    void reset() {
        ++timer;
        merges = 0;
    }

    void init(int u) {
        if (seen[u] != timer) {
            seen[u] = timer;
            par[u] = u;
            sz[u] = 1;
        }
    }

    int find(int u) {
        init(u);
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
        ++merges;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,int>>> edges(MAXW + 1);
    int maxWeight = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges[w].push_back({u, v});
        maxWeight = max(maxWeight, w);
    }

    vector<int> ans(MAXW + 1, -1);
    DSU dsu(n);

    while (k--) {
        int x;
        cin >> x;

        if (ans[x] != -1) {
            cout << ans[x] << '\n';
            continue;
        }

        dsu.reset();

        for (int w = x; w <= maxWeight; w += x) {
            for (auto [u, v] : edges[w]) {
                dsu.unite(u, v);
            }
        }

        ans[x] = n - dsu.merges - 1;
        cout << ans[x] << '\n';
    }

    return 0;
}

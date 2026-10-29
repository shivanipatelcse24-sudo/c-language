

#include <bits/stdc++.h>
using namespace std;

const int LOG = 17;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> up(LOG, vector<int>(n));
    vector<int> depth(n), tin(n), tout(n), pref(n);
    int timer = 0;

    vector<array<int, 3>> st;
    st.push_back({0, 0, 0});

    while (!st.empty()) {
        auto [u, p, exit] = st.back();
        st.pop_back();

        if (exit) {
            tout[u] = timer - 1;
            continue;
        }

        tin[u] = timer++;
        up[0][u] = p;

        for (int j = 1; j < LOG; j++)
            up[j][u] = up[j - 1][up[j - 1][u]];

        pref[u] = (u == 0 ? 0 : pref[p])
                  ^ (1 << (s[u] - 'a'));

        st.push_back({u, p, 1});

        for (int v : adj[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                st.push_back({v, u, 0});
            }
        }
    }

    vector<int> bit(n + 2);

    auto add = [&](int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    };

    auto get = [&](int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    };

    auto lca = [&](int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int d = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++)
            if (d & (1 << j))
                u = up[j][u];

        if (u == v)
            return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    };

    while (q--) {
        string op;
        int u, v;
        cin >> op >> u;

        if (op == "update") {
            char c;
            cin >> c;

            int delta = (1 << (s[u] - 'a'))
                      ^ (1 << (c - 'a'));

            add(tin[u] + 1, delta);
            add(tout[u] + 2, delta);

            s[u] = c;
        } else {
            cin >> v;

            int w = lca(u, v);

            int a = pref[u] ^ get(tin[u] + 1);
            int b = pref[v] ^ get(tin[v] + 1);

            int mask = a ^ b ^ (1 << (s[w] - 'a'));

            cout << ((mask & (mask - 1)) == 0
                     ? "true" : "false") << '\n';
        }
    }

    return 0;
}

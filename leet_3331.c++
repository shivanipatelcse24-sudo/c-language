
#include <bits/stdc++.h>
using namespace std;

vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int n = parent.size();

    vector<vector<int>> adj(n), child(n);

    for (int i = 1; i < n; i++) {
        adj[parent[i]].push_back(i);
    }

    vector<int> newParent = parent;
    vector<int> last(26, -1), prev(n, -1);

    stack<pair<int, int>> st;
    st.push({0, 0});

    while (!st.empty()) {
        auto [u, state] = st.top();
        st.pop();

        int c = s[u] - 'a';

        if (state == 0) {
            prev[u] = last[c];

            if (last[c] != -1)
                newParent[u] = last[c];

            last[c] = u;

            st.push({u, 1});

            for (int v : adj[u])
                st.push({v, 0});
        }
        else {
            last[c] = prev[u];
        }
    }

    for (int i = 1; i < n; i++) {
        child[newParent[i]].push_back(i);
    }

    vector<int> order;
    st.push({0, 0});

    while (!st.empty()) {
        int u = st.top().first;
        st.pop();

        order.push_back(u);

        for (int v : child[u])
            st.push({v, 0});
    }

    vector<int> ans(n, 1);

    for (int i = n - 1; i > 0; i--) {
        int u = order[i];
        ans[newParent[u]] += ans[u];
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> parent(n);

    for (int i = 0; i < n; i++) {
        cin >> parent[i];
    }

    string s;
    cin >> s;

    vector<int> ans = findSubtreeSizes(parent, s);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}

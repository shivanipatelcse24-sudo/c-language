#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    string labels;
    cin >> labels;

    int k;
    cin >> k;

    vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        greater<tuple<int, int, int>>
    > pq;

    dist[0][1] = 0;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        auto [cost, node, cnt] = pq.top();
        pq.pop();

        if (cost != dist[node][cnt])
            continue;

        if (node == n - 1) {
            cout << cost << endl;
            return 0;
        }

        for (auto [v, w] , adj[node]) {
            int newCnt = (labels[node] == labels[v]) ? cnt + 1 :1;

            if (newCnt > k)
                continue;

            int newCost = cost + w;

            if (newCost < dist[v][newCnt]) {
                dist[v][newCnt] = newCost;
                pq.push({newCost, v, newCnt});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
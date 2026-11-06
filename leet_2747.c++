
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3;

    vector<vector<int>> logs = {
        {1, 3},
        {2, 6},
        {1, 5}
    };

    int x = 5;

    vector<int> queries = {10, 11};

    sort(logs.begin(), logs.end());

    int m = queries.size();

    vector<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
        q.push_back({queries[i], i});
    }

    sort(q.begin(), q.end());

    vector<int> count(n + 1, 0);
    vector<int> ans(m);

    int left = 0, right = 0;
    int active = 0;

    for (auto [time, idx] : q) {

        while (right < logs.size() && logs[right][1] <= time) {
            int id = logs[right][0];

            if (count[id] == 0)
                active++;

            count[id]++;
            right++;
        }

        while (left < right && logs[left][1] < time - x) {
            int id = logs[left][0];

            count[id]--;

            if (count[id] == 0)
                active--;

            left++;
        }

        ans[idx] = n - active;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

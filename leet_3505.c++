#include <bits/stdc++.h>
using namespace std;

multiset<int> low, high;
long long sumLow = 0, sumHigh = 0;

void balance() {
    while (low.size() > high.size() + 1) {
        int x = *low.rbegin();
        low.erase(prev(low.end()));
        sumLow -= x;
        high.insert(x);
        sumHigh += x;
    }

    while (low.size() < high.size()) {
        int x = *high.begin();
        high.erase(high.begin());
        sumHigh -= x;
        low.insert(x);
        sumLow += x;
    }
}

void add(int x) {
    if (low.empty() || x <= *low.rbegin()) {
        low.insert(x);
        sumLow += x;
    } else {
        high.insert(x);
        sumHigh += x;
    }
    balance();
}

void removeNum(int x) {
    auto it = low.find(x);

    if (it != low.end()) {
        low.erase(it);
        sumLow -= x;
    } else {
        it = high.find(x);
        high.erase(it);
        sumHigh -= x;
    }
    balance();
}

long long getCost() {
    long long m = *low.rbegin();

    return m * low.size() - sumLow
         + sumHigh - m * high.size();
}

int main() {
    int n, x, k;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> x >> k;

    vector<long long> cost(n - x + 1);

    for (int i = 0; i < x; i++)
        add(nums[i]);

    cost[0] = getCost();

    for (int i = x; i < n; i++) {
        removeNum(nums[i - x]);
        add(nums[i]);
        cost[i - x + 1] = getCost();
    }

    const long long INF = 1e18;

    vector<vector<long long>> dp(
        k + 1, vector<long long>(n + 1, INF)
    );

    dp[0][0] = 0;

    for (int t = 0; t <= k; t++) {
        for (int i = 0; i <= n; i++) {
            if (dp[t][i] == INF)
                continue;

            if (i < n)
                dp[t][i + 1] = min(dp[t][i + 1], dp[t][i]);

            if (t < k && i + x <= n)
                dp[t + 1][i + x] = min(
                    dp[t + 1][i + x],
                    dp[t][i] + cost[i]
                );
        }
    }

    cout << dp[k][n] << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        dp[i] = dp[i - 1] + costs[i - 1] + 1;

        if (i >= 2) {
            dp[i] = min(dp[i],
                dp[i - 2] + costs[i - 1] + 4);
        }

        if (i >= 3) {
            dp[i] = min(dp[i],
                dp[i - 3] + costs[i - 1] + 9);
        }
    }

    cout << dp[n] << endl;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
    int cost1, cost2, costBoth;
    int need1, need2;

    cin >> cost1 >> cost2 >> costBoth;
    cin >> need1 >> need2;

    long long common = min(need1, need2);

    long long ans = common * min(costBoth, cost1 + cost2);

    ans += (long long)(need1 - common) * min(cost1, costBoth);

    ans += (long long)(need2 - common) * min(cost2, costBoth);

    cout << ans << endl;

    return 0;
}

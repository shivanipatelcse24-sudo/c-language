
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int MOD = 1e9 + 7;

    long long odd = 0, even = 1;
    long long sum = 0, ans = 0;

    for (int x : arr) {
        sum += x;

        if (sum % 2 == 0) {
            ans += odd;
            even++;
        } else {
            ans += even;
            odd++;
        }

        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}

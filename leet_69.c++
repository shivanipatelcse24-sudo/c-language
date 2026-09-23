#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;

    long long l = 0, r = x, ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;

        if (mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}
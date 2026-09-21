#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    sort(a.begin(), a.end());

    int ans = max(a[n-1] * a[n-2] * a[n-3],
                  a[0] * a[1] * a[n-1]);

    cout << ans;

    return 0;
}
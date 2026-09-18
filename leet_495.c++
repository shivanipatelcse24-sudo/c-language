#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, duration;
    cin >> n;

    vector<int> time(n);
    for(int &x : time) cin >> x;

    cin >> duration;

    int ans = 0;

    for(int i = 1; i < n; i++)
        ans += min(duration, time[i] - time[i-1]);

    ans += duration;

    cout << ans;

    return 0;
}
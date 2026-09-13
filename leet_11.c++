#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    int l = 0, r = n - 1, ans = 0;

    while(l < r) {
        int water = min(h[l], h[r]) * (r - l);
        ans = max(ans, water);

        if(h[l] < h[r])
            l++;
        else
            r--;
    }

    cout << ans;

    return 0;
}
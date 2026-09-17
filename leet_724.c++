#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int total = 0;

    for(int &x : a) {
        cin >> x;
        total += x;
    }

    int left = 0;

    for(int i = 0; i < n; i++) {
        if(left == total - left - a[i]) {
            cout << i;
            return 0;
        }
        left += a[i];
    }

    cout << -1;
    return 0;
}
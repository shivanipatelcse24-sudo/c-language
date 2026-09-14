#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> t(n);

    for(int i = 0; i < n; i++) {
        t[i].resize(i + 1);
        for(int j = 0; j <= i; j++)
            cin >> t[i][j];
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j <= i; j++)
            t[i][j] += min(t[i+1][j], t[i+1][j+1]);
    }

    cout << t[0][0];

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    if (n == 1 || n >= s.size()) {
        cout << s;
        return 0;
    }

    vector<string> v(n);
    int row = 0, dir = 1;

    for (char c : s) {
        v[row] += c;

        if (row == 0) dir = 1;
        if (row == n - 1) dir = -1;

        row += dir;
    }

    for (string x : v)
        cout << x;

    return 0;
}
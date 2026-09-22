#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x < 0) {
        cout << false;
        return 0;
    }

    int n = x, rev = 0;

    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }

    cout << (n == rev);
}
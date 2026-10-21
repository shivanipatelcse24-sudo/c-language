#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minOperations(string s) {
    string t = s;
    sort(t.begin(), t.end());

    if (s == t)
        return 0;

    if (s.size() == 2)
        return -1;

    char mn = t[0];
    char mx = t.back();

    if (s[0] == mn || s.back() == mx)
        return 1;

    for (int i = 1; i < (int)s.size() - 1; i++) {
        if (s[i] == mn || s[i] == mx)
            return 2;
    }

    return 3;
}

int main() {
    string s;
    cin >> s;

    cout << minOperations(s) << '\n';

    return 0;
}
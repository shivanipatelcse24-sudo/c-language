#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int i = s.size() - 1, count = 0;

    while (i >= 0 && s[i] == ' ')
        i--;

    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    cout << count;
}
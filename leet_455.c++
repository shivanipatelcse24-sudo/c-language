#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> g(n);
    for(int &x : g) cin >> x;

    cin >> m;

    vector<int> s(m);
    for(int &x : s) cin >> x;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    while(i < n && j < m) {
        if(s[j] >= g[i])
            i++;
        j++;
    }

    cout << i;
    return 0;
}
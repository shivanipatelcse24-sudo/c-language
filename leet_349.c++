#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    cin >> m;

    vector<int> b(m);
    for(int &x : b) cin >> x;

    set<int> s(a.begin(), a.end());

    for(int x : b)
        if(s.count(x)) {
            cout << x << " ";
            s.erase(x);
        }

    return 0;
}
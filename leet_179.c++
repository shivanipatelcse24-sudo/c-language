#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for(string &x : a) cin >> x;

    sort(a.begin(), a.end(), [](string x, string y) {
        return x + y > y + x;
    });

    if(a[0] == "0") {
        cout << "0";
        return 0;
    }

    for(string x : a)
        cout << x;

    return 0;
}

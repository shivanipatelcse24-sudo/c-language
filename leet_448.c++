#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    for(int x : a)
        a[abs(x) - 1] = -abs(a[abs(x) - 1]);

    for(int i = 0; i < n; i++)
        if(a[i] > 0)
            cout << i + 1 << " ";

    return 0;
}
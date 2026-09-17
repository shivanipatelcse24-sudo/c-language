#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    bool inc = true, dec = true;

    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) inc = false;
        if(a[i] > a[i-1]) dec = false;
    }

    cout << (inc || dec ? "true" : "false");

    return 0;
}
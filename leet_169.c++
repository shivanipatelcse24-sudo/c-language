#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int candidate = 0, count = 0;

    for(int x : a) {
        if(count == 0)
            candidate = x;

        if(x == candidate)
            count++;
        else
            count--;
    }

    cout << candidate;

    return 0;
}
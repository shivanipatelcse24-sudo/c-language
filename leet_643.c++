#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    int sum = 0;

    for(int i = 0; i < k; i++)
        sum += a[i];

    int maxSum = sum;

    for(int i = k; i < n; i++) {
        sum += a[i] - a[i-k];
        maxSum = max(maxSum, sum);
    }

    cout << (double)maxSum / k;

    return 0;
}
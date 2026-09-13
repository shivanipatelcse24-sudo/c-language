#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    int minPrice = prices[0];
    int profit = 0;

    for(int i = 1; i < n; i++) {
        profit = max(profit, prices[i] - minPrice);
        minPrice = min(minPrice, prices[i]);
    }

    cout << profit;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    vector<int> pre(n + 1, 0);

    for(int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + nums[i];

    int left, right;
    cin >> left >> right;

    cout << pre[right + 1] - pre[left];

    return 0;
}
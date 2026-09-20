#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
6 
    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    sort(nums.begin(), nums.end());

    int ans = 0;

    for(int i = 0; i < n; i += 2)
        ans += nums[i];

    cout << ans;

    return 0;
}
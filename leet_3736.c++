
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mx = *max_element(nums.begin(), nums.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += mx - nums[i];
    }

    cout << ans << endl;

    return 0;
}

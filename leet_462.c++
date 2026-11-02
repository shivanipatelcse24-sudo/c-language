
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int mid = n / 2;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(nums[i] - nums[mid]);
    }

    cout << ans << endl;

    return 0;
}

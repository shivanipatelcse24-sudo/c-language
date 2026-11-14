
#include <bits/stdc++.h>
using namespace std;

int minimumSumSubarray(vector<int>& nums, int l, int r) {
    int n = nums.size();
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += nums[j];

            int len = j - i + 1;

            if (len >= l && len <= r && sum > 0) {
                ans = min(ans, sum);
            }

            if (len > r)
                break;
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n, l, r;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> l >> r;

    cout << minimumSumSubarray(nums, l, r) << endl;

    return 0;
}

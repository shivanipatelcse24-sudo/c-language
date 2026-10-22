#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size();
    int zero = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero = i;
            break;
        }
    }

    auto check = [&](int step) {
        for (int i = 1; i < n; i++) {
            int prev = (zero + (i - 1) * step + n) % n;
            int curr = (zero + i * step + n) % n;

            if (nums[prev] > nums[curr])
                return false;
        }
        return true;
    };

    int ans = INT_MAX;

    if (check(1)) {
        ans = min(ans, zero);
        ans = min(ans, n - zero + 2);
    }

    if (check(-1)) {
        ans = min(ans, zero + 2);
        ans = min(ans, n - zero);
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minOperations(nums) << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3};
    int n = nums.size();

    sort(nums.begin(), nums.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long x = nums[i];

        if (i < n / 2)
            ans -= x * x;
        else
            ans += x * x;
    }

    cout << ans;
    return 0;
}
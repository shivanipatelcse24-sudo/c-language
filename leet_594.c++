#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    sort(nums.begin(), nums.end());

    int ans = 0, i = 0;

    for(int j = 0; j < n; j++) {
        while(nums[j] - nums[i] > 1)
            i++;

        if(nums[j] - nums[i] == 1)
            ans = max(ans, j - i + 1);
    }

    cout << ans;

    return 0;
}
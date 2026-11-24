
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        int mx = *max_element(nums.begin(), nums.end());
        int ml = 1;

        for (int x : nums) {
            ml = lcm(ml, x);
        }

        long long maxP = 1LL * ml * mx;

        for (int i = 0; i < n; i++) {
            long long product = 1;
            long long g = 0, l = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                if (product > maxP)
                    break;

                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << obj.maxLength(nums) << endl;

    return 0;
}

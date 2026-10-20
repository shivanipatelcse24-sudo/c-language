#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> a = nums;
    sort(a.begin(), a.end());

    int ans = 0;

    for (int k = 1; k <= n; k++) {
        if (n % k != 0) continue;

        bool ok = true;

        for (int i = 0; i < n && ok; i += k) {
            int drops = 0;

            for (int j = 0; j < k; j++) {
                if (nums[i + j] > nums[i + (j + 1) % k])
                    drops++;
            }

            if (drops > 1) {
                ok = false;
                break;
            }

            vector<int> b(nums.begin() + i,
                          nums.begin() + i + k);
            sort(b.begin(), b.end());

            for (int j = 0; j < k; j++) {
                if (b[j] != a[i + j]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) ans += k;
    }

    cout << ans << endl;
    return 0;
}
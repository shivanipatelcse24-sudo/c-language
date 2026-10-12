#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 6, 5, 8};
    int k = 2;
    const int MOD = 1000000007;

    vector<int> bits(30, 0);

    for (int x : nums) {
        for (int i = 0; i < 30; i++) {
            if (x & (1 << i))
                bits[i]++;
        }
    }

    long long ans = 0;

    while (k--) {
        long long x = 0;

        for (int i = 0; i < 30; i++) {
            if (bits[i] > 0) {
                x |= (1 << i);
                bits[i]--;
            }
        }

        ans = (ans + x * x) % MOD;
    }

    cout << ans;
    return 0;
}
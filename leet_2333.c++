#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<int> nums1 = {7, 11, 4, 19, 11, 5, 6, 1, 8};
    vector<int> nums2 = {4, 7, 6, 16, 12, 9, 10, 2, 10};
    int k1 = 3, k2 = 6;

    vector<int> d;
    long long k = (long long)k1 + k2, sum = 0;

    for (int i = 0; i < nums1.size(); i++) {
        d.push_back(abs(nums1[i] - nums2[i]));
        sum += d.back();
    }

    if (sum <= k) {
        cout << 0;
        return 0;
    }

    sort(d.rbegin(), d.rend());

    int l = 0, r = d[0];

    while (l < r) {
        int mid = l + (r - l) / 2;
        long long need = 0;

        for (int x : d)
            if (x > mid) need += x - mid;

        if (need <= k) r = mid;
        else l = mid + 1;
    }

    for (int &x : d) {
        if (x > l) {
            k -= x - l;
            x = l;
        }
    }

    for (int &x : d) {
        if (k > 0 && x == l && l > 0) {
            x--;
            k--;
        }
    }

    long long ans = 0;
    for (int x : d)
        ans += 1LL * x * x;

    cout << ans;
    return 0;
}
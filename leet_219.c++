#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    cin >> k;

    unordered_map<int, int> last;

    for(int i = 0; i < n; i++) {
        if(last.count(nums[i]) && i - last[nums[i]] <= k) {
            cout << "true";
            return 0;
        }

        last[nums[i]] = i;
    }

    cout << "false";
    return 0;
}
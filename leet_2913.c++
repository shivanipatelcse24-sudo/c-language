#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 1};
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        vector<int> seen(101, 0);
        int count = 0;

        for (int j = i; j < n; j++) {
            if (seen[nums[j]] == 0) {
                count++;
                seen[nums[j]] = 1;
            }

            ans += count * count;
        }
    }

    cout << ans;
    return 0;
}
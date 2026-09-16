#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int count = 0, ans = 0;

    for (int x : nums) {
        if (x == 1) {
            count++;
            ans = max(ans, count);
        } else {
            count = 0;
        }
    }

    cout << ans;

    return 0;
}
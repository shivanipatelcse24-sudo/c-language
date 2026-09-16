#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3, 2, 1};

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int ans;

    if (nums.size() < 3)
        ans = nums.back();
    else
        ans = nums[nums.size() - 3];

    cout << ans;

    return 0;
}
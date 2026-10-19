#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> target;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        if (nums[i] == target)
            cout << i << " ";
    }

    return 0;
}
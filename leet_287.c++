#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    slow = nums[0];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << slow;

    return 0;
}
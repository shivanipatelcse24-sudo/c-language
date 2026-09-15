#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    cin >> target;

    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if(first == n || nums[first] != target)
        cout << "-1 -1";
    else
        cout << first << " " << last;

    return 0;
}
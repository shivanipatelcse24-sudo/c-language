#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    int target;
    cin >> target;

    int l = 0, r = n - 1;

    while(l <= r) {
        int mid = l + (r - l) / 2;

        if(nums[mid] == target) {
            cout << "true";
            return 0;
        }

        if(nums[l] == nums[mid] && nums[mid] == nums[r]) {
            l++;
            r--;
        }
        else if(nums[l] <= nums[mid]) {
            if(nums[l] <= target && target < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else {
            if(nums[mid] < target && target <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    cout << "false";
    return 0;
}
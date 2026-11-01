
#include <bits/stdc++.h>
using namespace std;

int minMoves(vector<int>& nums) {
    int mn = *min_element(nums.begin(), nums.end());
    
    int ans = 0;
    for (int x : nums) {
        ans += x - mn;
    }
    
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minMoves(nums);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> nums = {4,1,2,1,2};

    int ans = 0;
    for(int x : nums)
        ans ^= x;

    cout << ans;

    return 0;
}
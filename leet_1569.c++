#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;
vector<vector<long long>> c;

long long solve(vector<int>& a) {
    if (a.size() <= 2)
        return 1;

    vector<int> left, right;

    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[0])
            left.push_back(a[i]);
        else
            right.push_back(a[i]);
    }

    long long x = solve(left);
    long long y = solve(right);

    return c[left.size() + right.size()][left.size()] * x % MOD * y % MOD;
}

int main() {
    vector<int> nums = {2, 1, 3};
    int n = nums.size();

    c.assign(n + 1, vector<long long>(n + 1, 1));

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }

    cout << (solve(nums) - 1 + MOD) % MOD;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums) cin >> x;

    int k = 0;

    for(int x : nums) {
        if(k < 2 || x != nums[k-2])
            nums[k++] = x;
    }

    cout << k << endl;

    for(int i = 0; i < k; i++)
        cout << nums[i] << " ";

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    sort(arr.begin(), arr.end(), [](auto a, auto b) {
        int x = digitSum(a.first);
        int y = digitSum(b.first);

        if (x == y)
            return a.first < b.first;

        return x < y;
    });

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i].second == i)
            continue;

        int j = i, count = 0;

        while (!visited[j]) {
            visited[j] = true;
            j = arr[j].second;
            count++;
        }

        swaps += count - 1;
    }

    cout << swaps << endl;
    return 0;
}
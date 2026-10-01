#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target) {
            cout << mid;
            return 0;
        }
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    cout << -1;

    return 0;
}
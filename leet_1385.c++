#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for (int i = 0; i < arr1.size(); i++) {
            bool found = false;

            for (int j = 0; j < arr2.size(); j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution s;

    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << s.findTheDistanceValue(arr1, arr2, d);

    return 0;
}
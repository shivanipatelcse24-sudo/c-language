#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    string ans = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;

        while (j < ans.size() && j < strs[i].size() &&
               ans[j] == strs[i][j]) {
            j++;
        }

        ans = ans.substr(0, j);
    }

    cout << ans;

    return 0;
}
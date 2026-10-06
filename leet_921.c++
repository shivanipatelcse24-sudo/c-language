#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int open = 0;
    int ans = 0;

    for (char c : s) {

        if (c == '(') {
            open++;
        }
        else {
            if (open > 0)
                open--;
            else
                ans++;
        }
    }

    ans = ans + open;

    cout << ans;

    return 0;
}
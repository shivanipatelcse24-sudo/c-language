#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 2, sum = 17;

    if (sum > num * 9) {
        cout << "";
        return 0;
    }

    string ans = "";

    while (sum >= 9) {
        ans += '9';
        sum -= 9;
    }

    if (sum > 0)
        ans += char('0' + sum);

    while (ans.size() < num)
        ans += '0';

    cout << ans;

    return 0;
}
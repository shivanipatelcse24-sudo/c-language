
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    while (s.size() > k) {
        string temp = "";

        for (int i = 0; i < s.size(); i += k) {
            int sum = 0;

            for (int j = i; j < i + k && j < s.size(); j++) {
                sum += s[j] - '0';
            }

            temp += to_string(sum);
        }

        s = temp;
    }

    cout << s;

    return 0;
}

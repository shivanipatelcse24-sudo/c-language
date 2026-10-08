#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    string ans = "";
    int count = 0;

    for (char c : s) {

        if (c == '(') {
            // Outer '(' ko add nahi karna
            if (count > 0)
                ans += c;

            count++;
        }
        else {
            count--;

            // Outer ')' ko add nahi karna
            if (count > 0)
                ans += c;
        }
    }

    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << removeOuterParentheses(s);

    return 0;
}
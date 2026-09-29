#include <iostream>
#include <string>
using namespace std;

int maxDepth(string s) {

    int depth = 0;
    int ans = 0;

    for (char ch : s) {

        if (ch == '(') {
            depth++;
            ans = max(ans, depth);
        }

        else if (ch == ')') {
            depth--;
        }
    }

    return ans;
}

int main() {

    string s = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s);

    return 0;
}
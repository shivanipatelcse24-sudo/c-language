#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool isValid(string s) {
    int count = 0;

    for (char c : s) {
        if (c == '(') {
            count++;
        }
        else if (c == ')') {
            count--;

            if (count < 0)
                return false;
        }
    }

    return count == 0;
}

vector<string> removeInvalidParentheses(string s) {

    vector<string> ans;
    queue<string> q;
    unordered_set<string> seen;

    q.push(s);
    seen.insert(s);

    bool found = false;

    while (!q.empty()) {

        string cur = q.front();
        q.pop();

        if (isValid(cur)) {
            ans.push_back(cur);
            found = true;
        }

        // Minimum removal mil gaya
        if (found)
            continue;

        for (int i = 0; i < cur.size(); i++) {

            if (cur[i] != '(' && cur[i] != ')')
                continue;

            string next = cur.substr(0, i)
                        + cur.substr(i + 1);

            if (seen.find(next) == seen.end()) {
                seen.insert(next);
                q.push(next);
            }
        }
    }

    return ans;
}

int main() {

    string s;
    cin >> s;

    vector<string> result = removeInvalidParentheses(s);

    cout << "[";

    for (int i = 0; i < result.size(); i++) {
        cout << "\"" << result[i] << "\"";

        if (i != result.size() - 1)
            cout << ", ";
    }

    cout << "]";

    return 0;
}
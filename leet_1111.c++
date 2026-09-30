#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans;
    int depth = 0;

    for (char c : seq) {
        if (c == '(') {
            depth++;
            ans.push_back(depth % 2);
        } 
        else {
            ans.push_back(depth % 2);
            depth--;
        }
    }

    return ans;
}

int main() {
    string seq;

    cout << "Enter parentheses string: ";
    cin >> seq;

    vector<int> ans = maxDepthAfterSplit(seq);

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
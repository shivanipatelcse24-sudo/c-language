#include <bits/stdc++.h>
using namespace std;

vector<string> createGrid(int m, int n) {
    vector<string> grid(m, string(n, '#'));

    // First row ko free bana do
    grid[0] = string(n, '.');

    // Last column ko free bana do
    for (int i = 0; i < m; i++) {
        grid[i][n - 1] = '.';
    }

    return grid;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<string> grid = createGrid(m, n);

    for (string row : grid) {
        cout << row << '\n';
    }

    return 0;
}
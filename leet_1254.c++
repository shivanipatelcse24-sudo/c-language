#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int convert(string s) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    int month = stoi(s.substr(0, 2));
    int day = stoi(s.substr(3, 2));

    for (int i = 0; i < month - 1; i++) {
        day += days[i];
    }

    return day;
}

int countDaysTogether(string arriveAlice, string leaveAlice,
                      string arriveBob, string leaveBob) {
    int start = max(convert(arriveAlice), convert(arriveBob));
    int end = min(convert(leaveAlice), convert(leaveBob));

    if (start > end)
        return 0;

    return end - start + 1;
}

int main() {
    string arriveAlice, leaveAlice, arriveBob, leaveBob;

    cin >> arriveAlice >> leaveAlice >> arriveBob >> leaveBob;

    cout << countDaysTogether(arriveAlice, leaveAlice,
                              arriveBob, leaveBob) << '\n';

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> free;

    priority_queue<pair<long long,pair<int,int>>,
    vector<pair<long long,pair<int,int>>>,
    greater<pair<long long,pair<int,int>>>> busy;

    for (int i = 0; i < servers.size(); i++) {
        free.push({servers[i], i});
    }

    vector<int> ans;
    long long time = 0;

    for (int i = 0; i < tasks.size(); i++) {

        time = max(time, (long long)i);

        while (!busy.empty() && busy.top().first <= time) {
            free.push(busy.top().second);
            busy.pop();
        }

        if (free.empty()) {
            time = busy.top().first;

            while (!busy.empty() && busy.top().first <= time) {
                free.push(busy.top().second);
                busy.pop();
            }
        }

        auto server = free.top();
        free.pop();

        int weight = server.first;
        int index = server.second;

        ans.push_back(index);

        busy.push({time + tasks[i], {weight, index}});
    }

    return ans;
}

int main() {
    int n, m;

    cin >> n;
    vector<int> servers(n);

    for (int i = 0; i < n; i++) {
        cin >> servers[i];
    }

    cin >> m;
    vector<int> tasks(m);

    for (int i = 0; i < m; i++) {
        cin >> tasks[i];
    }

    vector<int> ans = assignTasks(servers, tasks);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
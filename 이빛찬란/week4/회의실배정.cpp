#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<tuple<int, int, int>> meetings(N);
    for (int i = 0; i < N; i++) {
        int num, sTime, eTime;
        cin >> num >> sTime >> eTime;
        meetings[i] = make_tuple(eTime, sTime, num);
    }

    sort(meetings.begin(), meetings.end());

    vector<pair<int, int>> selected;
    int lastEnd = 0;

    for (int i = 0; i < (int)meetings.size(); i++) {
        int eTime = get<0>(meetings[i]);
        int sTime = get<1>(meetings[i]);
        int num = get<2>(meetings[i]);
        if (sTime >= lastEnd) {
            selected.push_back(make_pair(sTime, num));
            lastEnd = eTime;
        }
    }

    sort(selected.begin(), selected.end());

    cout << selected.size() << "\n";
    for (int i = 0; i < (int)selected.size(); i++) {
        if (i > 0) cout << " ";
        cout << selected[i].second;
    }
    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    // {종료, {시작, 번호}}
    vector<pair<int, pair<int, int>>> lst(N);
    for(int i=0; i<N; i++) {
        int id, s, e;
        cin >> id >> s >> e;
        lst[i] = {e, {s, id}};
    }
    sort(lst.begin(), lst.end());

    vector<int> result;
    int end_t = 0;
    for(int i=0; i<N; i++) {
        if (lst[i].second.first >= end_t) {
            result.push_back(lst[i].second.second);
            end_t = lst[i].first;
        }
    }
    cout << result.size() << "\n";
    for(int id : result) cout << id << " ";

    return 0;
}
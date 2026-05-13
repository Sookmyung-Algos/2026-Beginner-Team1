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
        int low, high;
        cin >> low >> high;
        lst[i] = {high-low, {low, high}};
    }
    sort(lst.begin(), lst.end()); // 보관 온도 범위 좁은 순

    vector<pair<int, int>> f; // 냉장고 온도
    f.push_back({lst[0].second.first, lst[0].second.second});
    // 냉장고 온도 범위가 보관 온도 안이라면 유지
    for(int i=1; i<N; i++) {
        for(pair<int, int> temp : f) {
            if ((lst[i].second.first > temp.second) || lst[i].second.second < temp.first) {
                f.push_back({lst[0].second.first, lst[0].second.second});
            }
            else {
                if (lst[i].second.first > temp.first) temp.first = lst[i].second.first;
                if (lst[i].second.second < temp.second) temp.second = lst[i].second.second;
            }
        }
    }
    cout << f.size();

    return 0;
}
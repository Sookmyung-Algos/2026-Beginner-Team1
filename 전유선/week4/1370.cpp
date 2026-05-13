#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int num;
    int start;
    int end;
};

// 종료시간 기준 정렬
bool cmp(Meeting a, Meeting b) {

    // 종료시간이 같으면 시작시간 작은 순
    if (a.end == b.end)
        return a.start < b.start;

    return a.end < b.end;
}

int main() {
    int N;
    cin >> N;

    vector<Meeting> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].num >> v[i].start >> v[i].end;
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> answer;

    int lastEnd = 0;

    for (int i = 0; i < N; i++) {

        // 안 겹칠 때 선택
        if (v[i].start >= lastEnd) {

            answer.push_back(v[i].num);

            lastEnd = v[i].end;
        }
    }

    cout << answer.size() << '\n';

    for (int x : answer) {
        cout << x << ' ';
    }
}
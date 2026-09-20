#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x > 0) {
            // 양수 우선순위 큐에 추가
            pq.push(x);
        } else {
            // 비어있을 때 0 출력
            if (pq.empty()) {
                cout << 0 << '\n';
            } else {
                // 가장 큰 값 출력 후 제거
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}
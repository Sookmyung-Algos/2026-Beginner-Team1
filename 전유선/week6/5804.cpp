#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> tree;

// distance만큼의 최소 간격을 유지하면서
// C개의 나무를 설치할 수 있는지 확인
bool canInstall(int distance) {
    int count = 1;
    int last = tree[0];

    for (int i = 1; i < N; i++) {
        if (tree[i] - last >= distance) {
            count++;
            last = tree[i];
        }
    }

    return count >= C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;

    tree.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    // 위치를 오름차순 정렬
    sort(tree.begin(), tree.end());

    // 이분 탐색 범위
    int left = 1;
    int right = tree[N - 1] - tree[0];

    int answer = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canInstall(mid)) {
            // mid만큼의 거리를 확보할 수 있다.
            // 더 큰 거리도 가능한지 확인
            answer = mid;
            left = mid + 1;
        }
        else {
            // mid는 너무 큰 거리 다.
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}
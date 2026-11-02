#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 충분히 큰 값 (무한대)

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break; // 거래자의 수가 0이면 종료

        // dist[i][j]: i번 거래자에서 j번 거래자로 정보가 전달되는 최단 시간
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

        // 자기 자신으로 가는 거리는 0으로 초기화
        for (int i = 1; i <= n; ++i) {
            dist[i][i] = 0;
        }

        // 입력 처리
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m; // i번 거래자가 소문을 전달할 수 있는 정보원의 수
            for (int j = 0; j < m; ++j) {
                int target, time;
                cin >> target >> time;
                dist[i][target] = time;
            }
        }

        // 플로이드-워셜 알고리즘 수행
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int best_person = -1;
        int min_max_time = INF;

        // 각 출발점(i)에서 가장 멀리 있는 사람까지의 시간을 구함
        for (int i = 1; i <= n; ++i) {
            int current_max = 0;
            bool reachable_all = true;

            for (int j = 1; j <= n; ++j) {
                if (dist[i][j] == INF) {
                    reachable_all = false; // 도달할 수 없는 거래자가 존재함
                    break;
                }
                current_max = max(current_max, dist[i][j]);
            }

            // 모든 사람에게 전달 가능하고, 이전 최댓값보다 더 적은 시간이 걸리는 경우 갱신
            if (reachable_all && current_max < min_max_time) {
                min_max_time = current_max;
                best_person = i;
            }
        }

        // 출력
        if (best_person == -1) {
            cout << "disjoint\n";
        }
        else {
            cout << best_person << " " << min_max_time << "\n";
        }
    }

    return 0;
}

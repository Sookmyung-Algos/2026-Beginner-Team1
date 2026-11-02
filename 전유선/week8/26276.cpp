#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 간선 정보 구조체
struct Edge {
    int to;
    int weight;
};

int N, M;
int S, E;
vector<vector<Edge>> adj;

// 신뢰도 기준이 K일 때, S에서 E까지 도달할 수 있는지 검사하는 함수
bool canReach(int K) {
    vector<bool> visited(N + 1, false);
    queue<int> q;

    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == E) return true; // 목적지 도달 성공

        for (const auto& edge : adj[curr]) {
            // 신뢰도가 K 이상이고 아직 방문하지 않은 학생인 경우에만 이동
            if (edge.weight >= K && !visited[edge.to]) {
                visited[edge.to] = true;
                q.push(edge.to);
            }
        }
    }

    return false; // 도달 불가능
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    adj.resize(N + 1);

    int max_weight = 0;
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // 양방향 친구 관계
        max_weight = max(max_weight, w);
    }

    cin >> S >> E;

    // 이분 탐색 (1 ~ max_weight)
    int low = 1, high = max_weight;
    int answer = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canReach(mid)) {
            answer = mid;   // 도달 가능하면 K값을 더 키워봄
            low = mid + 1;
        }
        else {
            high = mid - 1; // 도달 불가능하면 K값을 줄임
        }
    }

    cout << answer << "\n";

    return 0;
}

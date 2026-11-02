#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 10^11 이상을 커버할 수 있는 큰 값

struct Edge {
    int to;
    long long weight;
};

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        if (u == v) continue; // Self-loop 무시 (자기 자신으로 가는 경로는 최단 경로가 될 수 없음)
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    // 최단 거리 배열 및 경로 추적 배열
    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long w = edge.weight;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u; // v 정점의 이전 정점으로 u를 기록
                pq.push({ dist[v], v });
            }
        }
    }

    // N번 정점에 도달할 수 없는 경우 -1 출력
    if (dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    // N번 정점부터 역추적하여 경로 복원
    vector<int> path;
    for (int curr = n; curr != -1; curr = parent[curr]) {
        path.push_back(curr);
    }

    // 경로가 역순으로 담겼으므로 뒤집어줌
    reverse(path.begin(), path.end());

    // 경로 출력
    for (int i = 0; i < (int)path.size(); ++i) {
        cout << path[i] << (i == (int)path.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}

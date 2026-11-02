#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18; // 경로 합이 커질 수 있으므로 충분히 큰 값 사용

struct Edge {
    int to;
    long long weight;
    int id; // 간선 식별용 ID
};

int N, M;
vector<vector<Edge>> adj;
vector<pair<int, int>> edges; // 간선의 (u, v) 정보 저장
vector<long long> weights;     // 각 간선의 가중치

// 다익스트라 알고리즘
// doubled_edge_id: 가중치를 2배로 늘릴 간선의 ID (-1이면 늘리지 않음)
// parent_edge: 최단 경로 추적을 위한 parent 배열 (NULL이 아니면 기록)
long long dijkstra(int doubled_edge_id, vector<int>* parent_edge = nullptr) {
    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int id = edge.id;
            long long w = weights[id];

            // 지정된 간선인 경우 시간을 2배로 설정
            if (id == doubled_edge_id) {
                w *= 2;
            }

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (parent_edge) {
                    (*parent_edge)[v] = id; // v로 올 때 사용한 간선 ID 기록
                }
                pq.push({ dist[v], v });
            }
        }
    }

    return dist[N];
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    adj.resize(N + 1);
    weights.resize(M);

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w, i });
        adj[v].push_back({ u, w, i });
        edges.push_back({ u, v });
        weights[i] = w;
    }

    // 1. 원래 상태에서의 최단 거리 및 최단 경로 추적
    vector<int> parent_edge(N + 1, -1);
    long long original_dist = dijkstra(-1, &parent_edge);

    // N번 정점부터 1번 정점까지 역추적하여 최단 경로에 포함된 간선 ID 수집
    vector<int> path_edges;
    int curr = N;
    while (curr != 1) {
        int edge_id = parent_edge[curr];
        path_edges.push_back(edge_id);

        // 간선의 반대쪽 정점으로 이동
        int u = edges[edge_id].first;
        int v = edges[edge_id].second;
        curr = (curr == u) ? v : u;
    }

    // 2. 최단 경로 상의 간선들을 하나씩 2배로 늘려가며 최대 최단 거리 구하기
    long long max_dist = original_dist;

    for (int edge_id : path_edges) {
        long long new_dist = dijkstra(edge_id, nullptr);
        max_dist = max(max_dist, new_dist);
    }

    // 3. 최단 시간의 증가량 출력
    cout << max_dist - original_dist << "\n";

    return 0;
}

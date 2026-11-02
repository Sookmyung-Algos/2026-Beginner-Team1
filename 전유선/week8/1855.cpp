#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int cost;
};

int N, P, C;
vector<int> student_counts; // 각 장소별 학생 수
vector<vector<Edge>> adj;

// meeting_point에서 출발하여 다른 모든 장소까지의 최단 거리를 구하고,
// 모든 학생들의 이동 시간 합을 반환하는 함수
int get_total_time(int meeting_point) {
    vector<int> dist(P + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[meeting_point] = 0;
    pq.push({ 0, meeting_point });

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int next_d = d + edge.cost;

            if (dist[v] > next_d) {
                dist[v] = next_d;
                pq.push({ next_d, v });
            }
        }
    }

    // 모임 장소(meeting_point)로 모든 학생이 모일 때의 총 이동 시간 계산
    int total_time = 0;
    for (int i = 1; i <= P; ++i) {
        if (student_counts[i] > 0) {
            if (dist[i] == INF) return INF; // 도달할 수 없는 학생이 있다면 불가능
            total_time += dist[i] * student_counts[i];
        }
    }

    return total_time;
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> P >> C)) return 0;

    student_counts.assign(P + 1, 0);
    adj.resize(P + 1);

    // C개의 경로 정보 입력
    for (int i = 0; i < C; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({ v, cost });
        adj[v].push_back({ u, cost }); // 양방향 도로
    }

    // N명 학생들의 위치 입력 및 장소별 학생 수 집계
    for (int i = 0; i < N; ++i) {
        int loc;
        cin >> loc;
        student_counts[loc]++;
    }

    int min_total_time = INF;

    // 모든 장소(1 ~ P)를 모임 장소 후보로 테스트
    for (int i = 1; i <= P; ++i) {
        int current_total = get_total_time(i);
        min_total_time = min(min_total_time, current_total);
    }

    cout << min_total_time << "\n";

    return 0;
}

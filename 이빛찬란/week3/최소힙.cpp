#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else {
			// x가 0이 아닐 때만 큐에 추가
			pq.push(x);
		}
	}

	for (int i : v) {
		cout << i << "\n";
	}

	return 0;
}
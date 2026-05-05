#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	int n,x;
	priority_queue<int> pq;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				v.push_back(0);
			}
			else {
				v.push_back( pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
	cout<<"결과출력\n";
	for (int i : v) {
		cout << i<<"\n";
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#define MAX 100000
using namespace std;

int main() {
	int n, m,tmp;
	deque<int> A, B, C;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		B.push_back(tmp);
	}

	while (!A.empty() && !B.empty()) {
		if (A.front() <= B.front()) {
			C.push_back(A.front());
			A.pop_front();
		}
		else{
			C.push_back(B.front());
			B.pop_front();			
		}
	}
	if (A.empty()) {
		for (auto it = B.begin(); it != B.end(); it++) {
			C.push_back(*it);
		}
	}
	else if (B.empty()) {
		for (auto it = A.begin(); it != A.end(); it++) {
			C.push_back(*it);
		}
	}

	for (int i : C) {
		cout << i<<"\n";
	}

	return 0;
}
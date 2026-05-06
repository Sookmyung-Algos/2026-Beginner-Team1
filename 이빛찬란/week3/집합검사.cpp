#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, m,x;
	set<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << s.count(x);
	}
	return 0;
}
#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m,num=0;
	string buf;
	set<string> s;
	

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		s.insert(buf);
	}
	for (int i = 0; i < m; i++) {
		cin >> buf;
		if (s.count(buf)) {
			num++;
		}
	}
	cout << num;
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 누적합 배열
    vector<long long> prefix_sum(n);

    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;

        if (i == 0)
            prefix_sum[i] = val;
        else
            prefix_sum[i] = prefix_sum[i - 1] + val;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        long long q;
        cin >> q;

        // q 이상인 첫 번째 누적합의 위치
        int pile = lower_bound(prefix_sum.begin(), prefix_sum.end(), q)
            - prefix_sum.begin() + 1;

        cout << pile << '\n';
    }

    return 0;
}
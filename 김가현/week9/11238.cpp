#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[2][505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, p, q;
    if (!(cin >> n >> p >> q)) return 0;

    vector<string> X(n);
    vector<string> P1(p);
    vector<string> P2(q);

    for (int i = 0; i < n; i++) cin >> X[i];
    for (int i = 0; i < p; i++) cin >> P1[i];
    for (int i = 0; i < q; i++) cin >> P2[i];

    int prev = 0, curr = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= p; j++) {
            for (int k = 0; k <= q; k++) {
                int val = dp[prev][j][k];

                if (j > 0 && dp[curr][j - 1][k] > val) val = dp[curr][j - 1][k];
                if (k > 0 && dp[curr][j][k - 1] > val) val = dp[curr][j][k - 1];

                if (j > 0 && X[i] == P1[j - 1]) {
                    val = max(val, dp[prev][j - 1][k] + 1);
                }
                if (k > 0 && X[i] == P2[k - 1]) {
                    val = max(val, dp[prev][j][k - 1] + 1);
                }

                dp[curr][j][k] = val;
            }
        }
        swap(prev, curr);
    }

    cout << dp[prev][p][q] << "\n";

    return 0;
}
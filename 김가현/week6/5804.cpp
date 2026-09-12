#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> trees(N);

    for (int i = 0; i < N; i++) cin >> trees[i];
    sort(trees.begin(), trees.end());

    int low = 1;
    int high = trees[N - 1] - trees[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 1;
        int last_pos = trees[0];

        for (int i = 1; i < N; i++) {
            if (trees[i] - last_pos >= mid) {
                count++;
                last_pos = trees[i];
            }
        }

        if (count >= K) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}
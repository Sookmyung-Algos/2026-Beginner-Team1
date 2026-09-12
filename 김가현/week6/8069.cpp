#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> v(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i=0; i<Q; i++) {
        int q, idx;
        cin >> q;

        idx = lower_bound(v.begin(), v.end(), q) - v.begin();
        if (idx == N) cout << v[N-1] << "\n";
        else if (idx == 0) cout << v[0] << "\n";
        else {
            if (v[idx]-q < q-v[idx-1]) cout << v[idx] << "\n";
            else cout << v[idx-1] << "\n";
        }
    }
}
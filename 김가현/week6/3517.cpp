#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N;
    vector<int> v(N);
    for (int i=0; i<N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    cin >> Q;
    for (int i=0; i<Q; i++) {
        int q;
        cin >> q;

        if (binary_search(v.begin(), v.end(), q)) {
            cout << lower_bound(v.begin(), v.end(), q) - v.begin() << " ";
        }
        else cout << -1 << " ";
    }
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, temp, num=0, label;
    cin >> n;
    vector<int> bugs(n);

    for (int i=0; i<n; i++) {
        cin >> temp;
        num += temp;
        bugs[i] = num;
    }

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> label;
        cout << lower_bound(bugs.begin(), bugs.end(), label) - bugs.begin() + 1 << "\n";
    }
}
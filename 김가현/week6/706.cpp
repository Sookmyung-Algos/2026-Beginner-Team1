#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, money;
    cin >> n;
    vector<int> price(n);

    for (int i=0; i<n; i++) cin >> price[i];
    sort(price.begin(), price.end());

    cin >> q;
    for (int i=0; i<q; i++) {
        cin >> money;
        cout << upper_bound(price.begin(), price.end(), money) - price.begin() << "\n";
    }
}
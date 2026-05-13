#include <iostream>
using namespace std;

int main() {
    int n, s, c, y;
    long long total = 0, minprice = 10000;

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> c >> y;
        if (minprice >= c) {
            minprice = c;
        }
        total += minprice * y;
        minprice += s;
    }
    cout << total;
    return 0;

}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, a, b, c;
    int price;
    int cal;
    int tmp;
    vector<int> d;
    cin >> n;
    cin >> a >> b;
    cin >> c;

    cal = c;
    price = a;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        d.push_back(tmp);
    }
    sort(d.begin(), d.end(), greater<int>());
    for (int toping : d) {
        if (((double)(cal + toping) / (price + b)) > (double)(cal / price)) {
            cal += toping;
            price += b;
        }
    }
    cout << cal / price;
    return 0;
}
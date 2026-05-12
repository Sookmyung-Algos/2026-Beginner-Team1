#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    set<int> card;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        card.insert(x);
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;

        if (card.count(x)) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    return 0;
}
#include <iostream>
using namespace std;
#define MAX 1024

int paper[MAX][MAX];

void solve(int y, int x, int size) {
    int color = paper[y][x];
    bool same = true;

    for (int i = y; i < y + size && same; i++) {
        for (int j = x; j < x + size && same; j++) {
            if (paper[i][j] != color) {
                same = false;
            }
        }
    }

    if (same) {
        cout << color;
        return;
    }

    cout << 'X';
    int half = size / 2;
    solve(y, x, half);
    solve(y, x + half, half);
    solve(y + half, x, half);
    solve(y + half, x + half, half);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, n);
    cout << "\n";
    return 0;
}

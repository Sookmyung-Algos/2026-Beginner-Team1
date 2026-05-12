#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    set<string> S;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;
        S.insert(str);
    }
    cin >> M;
    int count = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (S.find(str) != S.end()) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int answer = 0;

    // 사람을 왼쪽부터 탐색
    for (int i = 0; i < N; i++) {

        // 사람이면
        if (s[i] == 'P') {

            // 먹을 수 있는 범위 탐색
            for (int j = max(0, i - K); j <= min(N - 1, i + K); j++) {

                // 햄버거 발견
                if (s[j] == 'H') {

                    // 먹음 처리
                    s[j] = 'X';

                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;
}
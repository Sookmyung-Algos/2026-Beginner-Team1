#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, k;
    int result = 0;
    string str;

    cin >> n >> k;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'P') {
            int start = max(0, i - k);
            int end = min(n - 1, i + k);

            for (int j = start; j <= end; j++) {
                if (str[j] == 'H') {
                    str[j] = 'X'; // 먹었다는 표시 
                    result++;
                    break;
                }
            }
        }
    }
    cout << result;
    return 0;
}
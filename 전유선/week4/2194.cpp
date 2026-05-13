#include <iostream>

using namespace std;

int main() {
    int N;
    long long S;

    cin >> N >> S;

    long long price, amount;

    long long minPrice = 99999999999;
    long long answer = 0;

    for (int i = 0; i < N; i++) {
        cin >> price >> amount;

        minPrice = min(minPrice + S, price);

        answer += minPrice * amount;
    }

    cout << answer;
}
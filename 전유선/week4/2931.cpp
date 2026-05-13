#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int A, B;
    cin >> A >> B;

    int C;
    cin >> C;
	// 2try... set은 중복허용이 안 되므로 vector과 sort를 사용한다.
    vector<int> topping(N);

    for (int i = 0; i < N; i++) {
        cin >> topping[i];
    }

    // 칼로리 높은 순으로 정렬
    sort(topping.begin(), topping.end(), greater<int>());

    int totalCal = C;   // 현재 총 칼로리
    int totalPrice = A; // 현재 총 가격

    int answer = totalCal / totalPrice;

    // 토핑을 추가
    for (int i = 0; i < N; i++) {
        totalCal += topping[i];
        totalPrice += B;

        int value = totalCal / totalPrice;

        answer = max(answer, value);
    }

    cout << answer;

    return 0;
}
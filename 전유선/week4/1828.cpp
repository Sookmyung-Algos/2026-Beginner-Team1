#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Chemical {
    int low;
    int high;
};

// 최고온도 기준 정렬
bool cmp(Chemical a, Chemical b) {
    return a.high < b.high;
}

int main() {
    int N;
    cin >> N;

    vector<Chemical> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].low >> v[i].high;
    }

    sort(v.begin(), v.end(), cmp);

    int fridge = 1;

    // 현재 냉장고 온도
    int temp = v[0].high;

    for (int i = 1; i < N; i++) {

        // 현재 냉장고로 보관 불가능할 때
        if (temp < v[i].low) {

            fridge++;

            // 새 냉장고 온도 설정
            temp = v[i].high;
        }
    }

    cout << fridge;
}
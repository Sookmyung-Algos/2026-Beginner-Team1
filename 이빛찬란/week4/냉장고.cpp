#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;


    vector<pair<int, int>> chemicals(n);
    for (int i = 0; i < n; i++) {
        int l, h;
        cin >> l >> h;
        chemicals[i] = { h, l }; // 정렬 기준이 될 high를 first에 넣음
    }

    // 최고 보관 온도 기준 오름차순 정렬
    sort(chemicals.begin(), chemicals.end());

    int count = 0;
    long long current_temp = -2000000000;

    for (int i = 0; i < n; i++) {
        int cur_high = chemicals[i].first;
        int cur_low = chemicals[i].second;

        // 현재 설정된 냉장고 온도가 이 물질의 최저 보관 온도보다 낮다면
        if (current_temp < cur_low) {
            count++; // 새 냉장고 추가
            current_temp = cur_high; // 이 냉장고의 온도를 현재 물질의 최고 온도로 고정
        }
    }

    cout << count << endl;

    return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, coin;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    vector<int> arr2(m);

    // 그냥 반복문 쓰면 런타임 에러 발생해서 정렬하고 upper_bound를 쓰자.
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        cin >> coin;

        auto it = upper_bound(arr.begin(), arr.end(), coin);
        cnt = it - arr.begin();
        arr2[i] = cnt;
    }
    for (int b : arr2) {
        cout << b << '\n';
    }

    return 0;
}*/

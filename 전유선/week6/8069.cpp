#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    vector<int> arr2(q);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        auto it = lower_bound(arr.begin(), arr.end(), temp);
        int index = it - arr.begin();

        if (index == 0) {
            cout << arr[0] << '\n';
        }
        // lower_bound가 배열에 있는 수들보다 크면 배열의 끝 위치 반환.
        else if (index == n) {
            cout << arr[n - 1] << '\n';
        }
        else {
            if ((arr[index] - temp) >= temp - arr[index - 1]) {
                cout << arr[index - 1] << '\n';
            }
            else {
                cout << arr[index] << '\n';
            }
        }
    }

    return 0;
}

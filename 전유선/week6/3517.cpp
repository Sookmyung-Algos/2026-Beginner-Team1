/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearchRecur(int A[], int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;

    if (A[mid] == target) return mid;
    if (A[mid] > target) return binarySearchRecur(A, low, mid - 1, target);

    return binarySearchRecur(A, mid + 1, high, target);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n;
    vector<int> arr1(n);

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> q;
    vector<int> arr2(q);

    for (int i = 0; i < q; i++) {
        cin >> arr2[i];
    }

    for (int target : arr2) {
        cout << binarySearchRecur(arr1.data(), 0, arr1.size() - 1, target) << ' ';
    }
}*/

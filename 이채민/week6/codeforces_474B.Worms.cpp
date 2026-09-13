#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> sum(n);

    int a;
    for (int i = 0; i < n; i++){
        cin >> a;

        if (i == 0)
            sum[i] = a;
        else
            sum[i] = sum[i - 1] + a;
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++){
        int q;
        cin >>q;

        int idx=lower_bound(sum.begin(), sum.end(), q)-sum.begin();

        cout << idx + 1 << '\n';
    }
    return 0;
}
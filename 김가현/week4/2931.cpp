#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 토핑 종류, 도우 가격, 토핑 가격, 도우 칼로리, 토핑 칼로리
    int N, A, B, C; 

    cin >> N;
    cin >> A >> B;
    cin >> C;

    vector<int> cal(N);
    for(int i=0; i<N; i++) {
        cin >> cal[i];
    }
    sort(cal.begin(), cal.end(), greater<int>());

    int ans=C/A;
    int pre=C;
    int temp;
    for(int i=0; i<N; i++) {
        pre += cal[i];
        temp = pre/(A+B*(i+1));
        if (temp > ans) ans=temp;
    }

    cout << ans;

    return 0;
}
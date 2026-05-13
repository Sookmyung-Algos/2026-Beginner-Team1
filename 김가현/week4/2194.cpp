#include <iostream>
#include <string>
using namespace std;

int main() {
    // N주, 리터 당 보관 가격, 리터 당 가격, 필요 우유량
    int N, S, C, Y; 
    cin >> N >> S;

    long long total = 0;
    int low_p = 5001;
    for(int i=0; i<N; i++) {
        cin >> C >> Y;
        
        if (C < (low_p+S)) low_p = C;
        else low_p += S;
        total += low_p*Y;
    }
    cout << total;

    return 0;
}
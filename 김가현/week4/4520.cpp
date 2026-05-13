#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    int count = 0;
    for(int i=0; i<S.size(); i++) {
        if (S[i] == 'P') {
            bool eat = false;

            for(int j=K; j>=1; j--) {
                if (i-j >=0 && S[i-j] == 'H') {
                    S[i-j] = 'N';
                    count++;
                    eat = true;
                    break;
                }
            }
            if (!eat) {
             for (int j=1; j<=K; j++) {
                    if (i+j < S.size() && S[i+j] == 'H') {
                            S[i+j] = 'N';
                    count++;
                        break;
                    }
                }
            }   
        }
    }
    cout << count;

    return 0;
}
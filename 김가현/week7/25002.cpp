#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M), C;
    int a=0, b=0;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    while(a<N && b<M) {
        C.push_back(A[a] <= B[b] ? A[a++] : B[b++]);
    }
    while (a < N) C.push_back(A[a++]);
    while (b < M) C.push_back(B[b++]);

    for(int i=0; i<N+M; i++) cout << C[i] << "\n";
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >>N>>K;

    vector<long long> tree(N);

    for (int i = 0; i < N; i++){
        cin >> tree[i];
    }

    sort(tree.begin(), tree.end());

    long long low = 1;
    long long high = tree[N-1]-tree[0];
    long long answer =0;

    while (low <= high){
        long long mid = (low + high) / 2;

        int count = 1;
        long long last = tree[0];

        for (int i = 1; i < N; i++){
            if (tree[i] - last >= mid){
                count++;
                last = tree[i];
            }
        }

        if (count>= K){
            answer = mid;
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    cout<<answer;
    return 0;
}

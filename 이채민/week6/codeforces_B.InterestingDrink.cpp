#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, xi, q, mi;
    vector<int> coin;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> xi;
        coin.push_back(xi);
    }

    sort(coin.begin(), coin.end());

    cin >> q;

    for(int i=0; i<q; i++){
        cin >> mi;
        int cnt= upper_bound(coin.begin(), coin.end(), mi) - coin.begin();

        cout<<cnt<<"\n";
    }
    return 0;
}

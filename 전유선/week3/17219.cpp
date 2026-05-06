#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<string, string> mp;
    string site, password;

    for (int i = 0; i < N; i++) {
        cin >> site >> password;
        mp.insert({ site, password });
        // mp[site] = password; 형식으로도 가능합니다.
    }

    for (int i = 0; i < M; i++) {
        cin >> site;
        // find를 통해 해당 키를 가진 반복자(iterator)를 찾고 value(second) 출력
        cout << mp.find(site)->second << '\n';
    }

    return 0;
}
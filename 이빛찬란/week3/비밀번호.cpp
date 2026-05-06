#include <iostream>
#include <map>				// map 자료구조 
using namespace std;

int main() {
	int n, m, i;				// 저장할 사이트-비밀번호 수, 검색할 시이트 수
	string site, pw,buf;	// 입력용 버퍼
	map<string, string> passwd;	// 변수 선언

	cin >> n >> m;

	for (i = 0; i < n; i++) {	// 원소 추가
		cin >> site >> pw;
		passwd.insert({site,pw});
	}

	for (i = 0; i < m;i++) { // 사이트를 입력받아 비밀번호 출력
		cin >> buf;
		auto it = passwd.find(buf);
		if(it!=passwd.end())
			cout <<it->second<<"\n";
	}

	return 0;
}


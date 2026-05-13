#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin>>N>>M;
    set<string> S;     //문자열 저장할 집합 S set 생성

    for (int i=0; i<N; i++){ 
        string str;
        cin >> str;
        S.insert(str); //set에 N개의 문자열 저장
    }

    int count=0;       //집합 S에 포함되는 문자열 개수 count

    for (int i=0; i<M; i++){
        string check;        //검사할 문자열 check
        cin >> check;
        if (S.count(check)){ //문자열이 set S에 존재하는 경우 (S.count(check)==1인 경우)
            count++;         //count 1 증가    
        }
    }

    cout << count;
    return 0;
}
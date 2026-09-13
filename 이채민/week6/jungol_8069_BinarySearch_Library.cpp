#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,Q;
    cin >>N>>Q;

    vector<int> A(N);

    for (int i = 0; i < N; i++){
        cin>>A[i];
    }

    for (int i = 0; i < Q; i++){
        int target;
        cin >>target;

        auto it=lower_bound(A.begin(), A.end(), target);

        if (it == A.begin()){
            cout << *it << '\n';
        }

        else if (it == A.end()){
            cout << A.back() << '\n';
        }

        else{
            int right =*it;
            int left =*(it - 1);

            if (target- left<=right- target){
                cout<< left<< '\n';
            }
            else{
                cout << right << '\n';
            }
        }
    }
    return 0;
}
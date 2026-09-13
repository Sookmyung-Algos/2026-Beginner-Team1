#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<int>& user, int target){
    int low=0;
    int high=user.size()-1;

    while(low <=high){
        int mid=(low+high)/2;

        if(user[mid]==target){
            return mid;
        }

        if(user[mid] < target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> user;
    int N, Q, a, b;

    cin >> N;

    for (int i=0; i<N; i++){
        cin >> a;
        user.push_back(a);
    }

    cin>>Q;

    for (int i=0; i<Q; i++){
        cin >>b;
        cout << BinarySearch(user, b) << " ";
    }

    return 0;
}

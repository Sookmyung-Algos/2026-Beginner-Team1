//quick sort

#include <iostream>
#include <utility>
#include <vector>
using namespace std;


void quicksort(vector<int>& A,int low,int high) {
	if (low >= high) {
		return;
	}
	int pivot=A[low];
	int i = low+1;
	int j = high;
	while (i <= j) {
		while (i <= j && A[i] <= pivot) {
			i++;
		}
		while (j >= i && A[j] >= pivot) {
			j--;
		}
		if (i < j) {
			swap(A[i], A[j]);
		}
	}
	swap(A[low], A[j]);
	for (int i : A) {
		cout << i << " ";
	}
	cout << "\n";
	quicksort(A, low, j - 1);
	quicksort(A, j+1, high);
	
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n,tmp;
	vector<int> lst;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		lst.push_back(tmp);

	}
	quicksort(lst, 0, n - 1);
	return 0;
}
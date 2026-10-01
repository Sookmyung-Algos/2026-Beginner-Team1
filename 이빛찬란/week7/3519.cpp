//merge sort


#include <iostream>
#include <utility>
#include <vector>
#define MAX 1000000
using namespace std;

void mergesort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);
void printAll();


int lst[MAX];
int B[MAX];
int n;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> lst[i];
	}
	mergesort(lst, 0, n - 1);
	
	return 0;
}

void mergesort(int A[], int low, int high) {
	if (low >= high) {
		return;
	}
	int mid = (low+high)/2;
	mergesort(A, low, mid);
	mergesort(A, mid+1, high);
	merge(A, low, mid ,high);
}

void merge(int A[], int low, int mid, int high) {
	int i=low, j=mid+1;
	
	while (i<=mid && j<=high) {
		if (A[i] >= A[j]) {
			B[i + j-mid - 1] = A[j];
			j++;
		}
		else {
			B[i + j -mid- 1] = A[i];
			i++;
		}
	}
	if (i > mid) { //mid+1-high 부분까지 추가
		for (int k = j; k <= high; k++) {
			B[i + k-mid-1] = A[k];
		}

	}
	else if (j > high) { //low-mid 부분까지 추가
		for (int k = i; k <= mid; k++) {
			B[ j + k-mid-1] = A[k];
		}
	}
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
	printAll();

}

void printAll() {
	for (int i = 0; i < n; i++) {
		cout << lst[i] << " ";
	}
	cout << "\n";
}


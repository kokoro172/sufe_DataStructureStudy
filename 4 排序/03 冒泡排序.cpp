#if 0
#include<iostream>
using namespace std;


void bubbleSort(int a[11], int n) {
	bool isS = false;
	for (int i = 0; i < n; i++) {
		isS = false;
		for (int j = 0; j < n - i - 1; j++) {	//从n开始往前的i个数已经排好了
			if (a[j - 1] > a[j]) {	//升序
				swap(a[j - 1], a[j]);
				isS = true;
			}
		}
		if (!isS) break;
	}
}


int main() {
	int a[] = { 1,11,12,1,0,6,5,4,58,6,22 };
	int n = 11;
	bubbleSort(a, n);
	for (int i : a) cout << i << " ";
	cout << endl;
}
#endif
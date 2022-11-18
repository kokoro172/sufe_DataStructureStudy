#if 0
#include<iostream>
using namespace std;

//a[]：传入的数组，low：数组起始下标，high：数组结束下标
void quickSort(int a[], int low, int high) {
	if (high <= low) return;	//当数组只剩下一个时返回
	int i = low, j = high, key = a[low];	//i、j为哨兵，key为基准值

	while (true) {
		while (a[j] >= key) {	//先从右往左找比基准值小的
			j--;	//从后往前找
			if (j == low) break;	//两个哨兵相遇就停止
		}
		while (a[i] <= key) {	//再从左往右找比基准值大的
			i++;	//从前往后找
			if (i == high) break;	//两个哨兵相遇就停止
		}

		if (i >= j) break;	//两个哨兵相遇就停止整个寻找流程
		swap(a[i], a[j]);	//交换哨兵jio下的数
	}
	a[low] = a[j];	//交换这两个数，可以直接用swap函数
	a[j] = key;		//swap(a[low], a[j]);

	//for (int tem = 0; tem <= 9; tem++) cout << a[tem] << " ";
	//cout << "\n";

	quickSort(a, low, j - 1);	//对左边进行相同操作
	quickSort(a, j + 1, high);	//对右边进行相同操作
}

int main() {
	int a[10] = { 20,10,90,99,40,50,30,60,80,70 };
	quickSort(a, 0, 9);
	for (int i : a) cout << i << " ";
	cout << "\n";
}

#endif
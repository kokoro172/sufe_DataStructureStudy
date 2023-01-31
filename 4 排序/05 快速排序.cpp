#if 0
#include<iostream>
using namespace std;
const int N = 8;

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

	for (int tem = 0; tem <= N; tem++) cout << a[tem] << " ";
	cout << "\n";

	quickSort(a, low, j - 1);	//对左边进行相同操作
	quickSort(a, j + 1, high);	//对右边进行相同操作
}

//void quick(int  a[], int low, int up)
//{
//	int i, j;
//	int t;
//	
//	if (low < up)
//	{
//		i = low;
//		j = up;
//		t = a[low];
//		while (i != j)
//		{
//			while (i<j && a[j]>t)   j--;
//			if (i < j)  a[i++] = a[j];
//			while (i < j && a[i] <= t)   i++;
//			if (i < j)  a[j--] = a[i];
//		}
//		a[i] = t;
//		for (int tem = 0; tem <= 9; tem++) cout << a[tem] << " ";
//		cout << "\n";
//		quick(a, low, i - 1);
//		quick(a, i + 1, up);
//	}
//}
void quick(int a[], int low, int up)
{
	int i, j;
	int t;
	// 如果 low < up，说明当前还有元素没有排序
	if (low < up) {
		i = low;
		j = up;
		t = a[low];
		// 将 t 插入到合适的位置
		while (i != j) {
			// 从后往前找到第一个小于 t 的数
			while (i < j && a[j] > t) {
				j--;
			}
			if (i < j) {
				// 将这个数放到 t 的左边
				a[i++] = a[j];
			}
			for (int tem = 0; tem <= N; tem++) {
				cout << a[tem] << " ";
			}
			cout << "\n";

			// 从前往后找到第一个大于 t 的数
			while (i < j && a[i] <= t) {
				i++;
			}
			if (i < j) {
				// 将这个数放到 t 的右边
				a[j--] = a[i];
			}
			for (int tem = 0; tem <= N; tem++) {
				cout << a[tem] << " ";
			}
			cout << "\n";
		}
		// 最后将 t 放到合适的位置
		a[i] = t;
		// 输出每次排序的结果

		cout << "\n";
		// 分治排序，将 t 的左边和右边分别排序
		quick(a, low, i - 1);
		quick(a, i + 1, up);
	}
}



int main() {
	int a[] = { 46,26,22,68,48,42,36,84,66 };
	
	//quickSort(a, 0, N);
	//cout << "\n";
	int b[] = { 46,26,22,68,48,42,36,84,66 };
	quick(b, 0, N);
}

#endif
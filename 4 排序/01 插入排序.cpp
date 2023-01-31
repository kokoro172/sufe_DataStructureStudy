#if 0

#include <iostream>
using namespace std;

//求出数组长度
////int len = getLength(a);	//获取数组长度
//template<class T>
//int getLength(T a[]) {
//	int i = 0;
//	while(a[i] != '\0')
//		i++;
//	return i + 1;
//}

//将第n个数插入到前面n-1个排好序的数组中
void insertionSort(int a[], int len) {
	for (int i = 1; i < len; i++) {	//最外层遍历第二个及后面的数
		for (int j = i; j > 0; j--) {	//与该数前面的数做比较
			if (a[j] < a[j - 1]) {	//升序
				swap(a[j - 1], a[j]);	//与该数前面更大的数做交换，相当于把它提出来，再让大于它的所有元素后移一位，再塞过去
			}
			else
				break;
		}
	}
}

int main() {
	int a[10] = { 1,5,3,6,2,45,51,6,33,0 };
	insertionSort(a, 10);
	for (int i : a)
		cout << i << " ";
	return 0;
}
#endif
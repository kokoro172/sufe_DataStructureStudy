#if 0
#include<iostream>
using namespace std;

//int a[]为传入的数组，int n为数组长度
void dirSelSort(int a[], int n) {
	int i = 0;	//i用于指向排好序的末尾
	int search = 1;	//用于遍历后面的内容
	int min = 0;	//最小值位置
	for (; i < n; i++) {
		search = i + 1;
		min = i;
		while (search < n) {//找到最小值编号
			if (a[search] < a[min]) {
				min = search;
			}
			search++;
		}//找到了最小值编号，跟search值无关了

		//开始替换
		int tem = a[min];
		while (min > i) {
			a[min] = a[min - 1];	//每一个都后移一位
			min--;
		}
		a[i] = tem;
	}
}

int main() {
	int a[10] = { 1,5 ,6, 8, 9, 6, 45 ,5, 2, 1 };
	dirSelSort(a, 10);
	for (int i : a) cout << i << " ";
}
#endif
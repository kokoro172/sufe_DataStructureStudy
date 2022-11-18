#if 0
#include<iostream>
using namespace std;

//将数组a的beg到mid和mid+1到end的两组通过数组b合并到一起。传入的是数组下标，而不是个数。
void merge(int* a, int* b, int beg, int mid, int end) {
	int i = beg,	//i 是遍历前半部分数组，上限是mid
		j = mid + 1, //j 是第二个数组起始的下标，上限是end
		k = beg;	//k 是遍历数组b，上限是end

	while (i <= mid && j <= end) {	//开始合并，i、j记录比较到这两半数组的哪里了
		if (a[i] < a[j])	//看这两部分中，哪个值更小，如果a[i]更小就把它塞到b[k]里面去。
			b[k++] = a[i++];	//++直接放在[]里，不用单独写，更简洁
		else
			b[k++] = a[j++];	//如果a[j]更小就把它塞到b[k]里面去。
	}

	while (i <= mid) b[k++] = a[i++];	//如果j到顶了，即后半部分全部塞进去了，那么前半部分直接按顺序填入即可
	while (j <= end) b[k++] = a[j++];	//同理

	for (i = beg; i <= end; i++)
		a[i] = b[i];
}

void mergeSort(int a[], int b[], int begin, int end) {
	int mid;
	if (begin < end) {
		mid = begin + (end - begin) / 2;	//二分，求出中间的下标
		mergeSort(a, b, begin, mid);	//左
		mergeSort(a, b, mid + 1, end);	//右
		merge(a, b, begin, mid, end);	//合并
	}
}



int main() {
	int a[10] = { 20,10,90,99,40,50,30,60,80,70 };
	int b[10];
	mergeSort(a, b, 0, 9);
	for (int i : a)
		cout << i << " ";
	cout << "\n";
	return 0;
}
#endif
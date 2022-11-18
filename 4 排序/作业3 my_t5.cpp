#if 0
#include<iostream>
constexpr int N = 10;	//数组长度
using namespace std;

//void printArr(int a[]) {
//	for(int i =0; i < N; i++)
//		cout << a[i] << " ";
//	cout << "\n";
//}


//利用pos数组记录长度为a的数组的升序的“断掉的地方”，
//pos记录的是升序的起始位置，如果需要上一个组的结束位置，减一即可
//n是a 的长度
int getPos(int a[], int pos[]) {
	int tem = 1;	//pos要记录的下标从1开始
	pos[0] = 0;	//首先开头记录为0，因为第一个组的起始位置一定是0
	for (int i = 0; i < N - 1; i++) {//注意此处的 n - 1 ，因为是i+1，防止越界！
		if (a[i] > a[i + 1]) {	//举例：1 2 3 5 0 1 2 3 中，从5到0就是个断点，此时5 > 0，记录好0的位置
			pos[tem++] = i + 1;//记录非升序的部分，这样就可以分成多个升序的组，通过pos记录下标
		}
	}
	return tem;	//返回pos的尾标
}

//将数组a的beg到mid和mid+1到end的两组通过数组b合并到一起
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
	//cout << "a= "; printArr(a); cout << "\n"; //debug
	//cout << "b= "; printArr(b); cout << "\n";	//debug
}

//a[]:原始数组，b[]：临时数组
void mergeSort(int a[],int b[]) {
	int pos[N];	//定义pos数组
	int posLen = getPos(a, pos);	//生成pos数组并获取其长度

	//总需的merge次数为：组数（posLen） - 1。
	for (int i = 0; i < posLen - 2; i++) {	//排序
		merge(a, b, pos[0], pos[i + 1] - 1, pos[i + 2] - 1);
		//cout << "a merge = "; printArr(a); cout << "\n"; //debug
	}//这个过程完毕后，还会剩下最后两个组

	merge(a, b, pos[0], pos[posLen - 1] - 1, N - 1);	//合并最后的2组
}


int main() {
	int a[N] = {1, 2, 3, 0, 1, 0 ,5 ,6, 5, 4};	//分成5组
	int b[N];
	mergeSort(a, b);
	for (int i : a) cout << i << " ";
}
#endif
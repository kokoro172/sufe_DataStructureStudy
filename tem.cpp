#if 0
// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
#include<iostream>
using namespace std;

/**
 * . 这是注释实验文字
 *
 * \param a 要排序的数组
 * \param i i是什么捏
 * \param n 大概是数组长度吧
 */
void siftdown(int  a[], int  i, int  n)
{
	int j;
	int t;
	t = a[i];
	while ((j = 2 * i + 1) < n)
	{
		if (j < n - 1 && a[j] > a[j + 1]) j++;
		if (t > a[j])

		{
			a[i] = a[j];
			i = j;
		}
		else break;
	} /*while */
	a[i] = t;
}

void heap_sort(int a[], int n)
{
	int i;
	int t;
	for (i = (n - 2) / 2; i >= 0; i--)
		siftdown(a, i, n);
	for (i = n - 1; i > 0; i--)
	{
		t = a[0];
		a[0] = a[i];
		a[i] = t;
		siftdown(a, 0, i);
	}
}

void testAlignment() {
	int a[3];
	int aLongNumberVariable = 1;
	a[0] = 10;
	a[aLongNumberVariable] = 4;
	a[2] = 3;
	
}

int main() {
	int a[6] = { 1,59,23,5,66,0 };
	heap_sort(a, 6); int i = 0;

	return 0;
}
#endif
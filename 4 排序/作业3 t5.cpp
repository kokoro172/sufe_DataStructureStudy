#if 0
#include <algorithm>
#include <iostream>

using namespace std;

int getIndex(int* a, int* t, int n)
{
    // 记录初始自然排好序的子数组段的起始下标及个数
    int cnt = 0;
    t[cnt++] = 0;	// 第一个下标为0
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] < a[i])
            t[cnt++] = i + 1;
    }
    return cnt;
}

// 合并a中有序的两段子数组到b对应的位置
// l是第一个有序子数组段的起始下标
// m是第一个有序子数组段的末尾下标
// r是第二个有序子数组段的末尾下标
void merge(int* a, int* b, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;	// j为第二个的起始下标
    int k = left;
    while (i <= mid && j <= right)	// 合并两段
    {
        if (a[i] <= a[j])	// 每次取两段中较小的一个
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    // 合并两段中的剩余部分
    while (i <= mid) b[k++] = a[i++];
    while (j <= right)	b[k++] = a[j++];
}

void mergePass(int* a, int* b, int* t, int s, int n, int cnt)
{
    int i = 0;
    while (i <= cnt - 2 * s)	// 用子段数组个数控制循环
    {
        if (i + 2 * s < cnt)
            merge(a, b, t[i], t[i + s] - 1, t[i + 2 * s] - 1);
        else
            merge(a, b, t[i], t[i + s] - 1, n - 1);
        i = i + 2 * s;
    }
    // 剩余未合并的不足s
    if (i + s < cnt)
        merge(a, b, t[i], t[i + s] - 1, n - 1);
    else if (i < cnt)
        for (int j = t[i]; j <= n - 1; j++)
            b[j] = a[j];
}

void mergeSort(int* a, int* t, int n, int cnt)
{
    // s指的是每次合并的子段数或者说步长
    // s = 1时是是对于初始分段1-1合并
    // s = 2时是相对与初始分段2-2合并，2是之前合并好的1-1
    int b[100];
    int s = 1;
    while (s < cnt)
    {
        mergePass(a, b, t, s, n, cnt);	// 合并数组到b
        s += s;
        mergePass(b, a, t, s, n, cnt);	// 合并数组回a
        s += s;
    }
}


int main()
{
    int n;
    int a[100], t[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = getIndex(a, t, n);
    mergeSort(a, t, n, cnt);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}
#endif
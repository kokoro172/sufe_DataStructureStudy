//#include<iostream>
//constexpr auto MAXN = 10;;
//using namespace std;
//
//template<class T>
//void printArray(T a[], int n) {
//    for (int i = 0; i < n; i++) cout << a[i] << " ";
//    cout << "\n";
//}
//
//void insertion_sort(int a[], int n) {
//
//}
//
//template<class T>
//void selection_sort(T a[], int n)
//{
//    T i, j, k;
//    T t;
//    for (i = 0; i < n - 1; i++)
//    {
//        k = i;
//        for (j = i + 1; j < n; j++)
//            if (a[k] > a[j]) k = j;
//        swap(a[i], a[k]);
//    }
//}
//
//template<class T>
//void bubble_sort(T a[], int n) {
//    for (int i = 0; i < n; i++) {
//        for (int j = i + 1; j < n; j++) {
//            if (a[i] < a[j])
//                swap(a[i], a[j]);
//        }
//    }
//}
//
//void merge(int  a[], int b[], int L, int m, int n)
//{
//    int i, j, k;
//    i = L;
//    j = m + 1;
//    k = L;
//    while (i <= m && j <= n)
//        if (a[i] <= a[j])
//            b[k++] = a[i++];
//        else b[k++] = a[j++];
//    while (i <= m)
//        b[k++] = a[i++];
//    while (j <= n)
//        b[k++] = a[j++];
//}
//
//void mpass(int a[], int b[], int n, int  L)
//{
//    int i, j;
//    i = 0;
//    while (i + 2 * L <= n)
//    {
//        merge(a, b, i, i + L - 1, i + 2 * L - 1);
//        i += 2 * L;
//    }
//    if (i + L < n) merge(a, b, i, i + L - 1, n - 1);
//    else for (j = i; j < n; j++)
//        b[j] = a[j];
//}
//void merge_sort(int a[], int n)
//{
//    int b[MAXN];
//    int L;
//    L = 1;
//    while (L < n)
//    {
//        mpass(a, b, n, L);
//        L *= 2;
//        mpass(b, a, n, L);
//        L *= 2;
//    }
//}
//
//int main() {
//    int a[9] = { 1,6,4,0,9,234,5,4,5 };
//    float b[4] = { 1.1 , 5.2, 9, 0.4 };
//    merge_sort(a, 9);
//    printArray(a, 9);
//}
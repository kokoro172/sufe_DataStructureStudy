//#include<iostream>
//using namespace std;
//
//void siftdown(int  a[], int  i, int  n)
//{
//    int j;
//    int t;
//    t = a[i];
//    while ((j = 2 * i + 1) < n)
//    {
//        if (j < n - 1 && a[j] > a[j + 1]) j++;
//        if (t > a[j])
//        {
//            a[i] = a[j];
//            i = j;
//        }
//        else break;
//    } /*while */
//    a[i] = t;
//}
//void heap_sort(int a[], int n)
//{
//    int i;
//    int t;
//    for (i = (n - 2) / 2; i >= 0; i--)
//        siftdown(a, i, n);
//    for (i = n - 1; i > 0; i--)
//    {
//        t = a[0];
//        a[0] = a[i];
//        a[i] = t;
//        siftdown(a, 0, i);
//    }
//}
//int main() {
//    int a[6] = { 1,59,23,5,66,0 };
//    heap_sort(a, 6);
//    for (int i : a)
//        cout << i << " ";
//    cout << "\n";
//    return 0;
//}
#if 0
#include<iostream>
using namespace std;


/*template<typename T>
void shell_sort(T array[], int length) {
    int h = 1;
    while (h < length / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i++) {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h) {
                swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
}*/


template<class T>
void shellSort(T a[], int length) {   // a[]:传入的要排序的数组, length:数组长度
    //int length = sizeof(a) / sizeof(a[0]);  // 求数组长度

    // interval作为分组间距，每次自除以2，最后肯定会变成1和0
    for (int interval = length / 2; interval; interval /= 2) {   

        // arrayNum作为组数，同时也作为起始位置。遍历每组，在组内排序
        for (int arrayNum = 0; arrayNum < interval; arrayNum++) { 
/*-—--—-—-—-—-—--—-—-—--—-—以下是插入排序-—--—-—-—--—-—-—--—-—-—-*/

            // numBeSort:将要插入的数，从第一个数开始
            // 考虑到下面的是用a[numBeSort] > a[numBeSort + interval]，所以是numBeSort + intrval < length
            // 每次加interval就算是分组了
            for (int numBeSort = arrayNum; numBeSort + interval < length; numBeSort += interval) {

                // 采用前面的插入排序方法
                for(int i = numBeSort; i >= 0; i -= interval)  {
                    if (a[i + interval ] < a[i])    // 把小的往前面插，升序
                        swap(a[i], a[i + interval]);
                }
            }
        }
    }
}

int main() {
    int a[] = { 778,5,3,8,94,0,2,3,15,8,1,74,5,4 };
    shellSort(a, 14);
    for (int i : a)
        cout << i << "  ";
    cout << endl;
}

#endif
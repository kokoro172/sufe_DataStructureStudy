#if 0
#include<iostream>
constexpr auto N = 10;	//有10个桶，0~9;
constexpr auto DIG = 4;	//最大位数为4;
using namespace std;


struct node { 
    int data;
    node* link;
};

//作用：获取a的倒数第n + 1位数字
int getNNum(int a, int n) {
    while (n--)
        a = a / N;  //这里的N可以是10，为了使程序统一
    return a % N;
}

void radixSort(node* arr) {
    if (arr == NULL) return;

    node* p = arr;
    for (int i = 0; i < DIG; i++) { //排4次
        node* head[N] = { NULL };  //十个桶的头结点 一定要放在里面，相当于初始化！
        node* tail[N] = { NULL };  //十个桶的尾结点

        p = arr;    //从开头开始
        while (p != NULL) { //入桶，这一段是非常经典的创建新结点然后加到链表末尾的操作
            int temp = getNNum(p->data, i); //获取本轮次对应的位数的值
            if (head[temp] == NULL) {   //如果头结点为空
                head[temp] = new node;  //开辟头结点
                head[temp]->data = p->data; //赋值
                head[temp]->link = NULL;    //赋值
                tail[temp] = head[temp];    //更新尾结点
            }
            else {
                node* q = new node; //开辟一个新结点
                q->data = p->data;  //对新结点赋值
                q->link = NULL;     //同上
                tail[temp]->link = q;   //连接尾结点
                tail[temp] = q; //更新尾结点
            }
            p = p->link;    //指向下一个数
        }

        //出桶
        p = arr;
        for (int j = 0; j < N; j++) {   //j就是桶对应的数   
            node* tmp = head[j];
            while (tmp != NULL && p != NULL) {
                p->data = tmp->data;    //覆盖式插回
                p = p->link;
                tmp = tmp->link;
            }
        }
    }
}

//创建随机链表
node* createRandLink()
{
    srand((unsigned int)time(NULL));
    node* head = NULL, * p, * q;
    int n = rand() % 15;   //n为有序链表的起点

    if (N == 0) return NULL;

    head = new node;
    p = head;
    p->data = n;
    p->link = NULL;

    for (int i = 1; i < N; i++) {
        q = new node;
        q->data = rand() % 9999;  //随机数
        q->link = NULL;
        p->link = q;
        p = q;
    }
    return head;
}

void printLink(node* head) {
    node* p = head;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->link;
    }
    cout << "\n";
}

int main() {
    node* arr = createRandLink();
    printLink(arr);

    radixSort(arr);
    printLink(arr);
    return 0;
}
#endif
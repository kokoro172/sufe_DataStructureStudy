#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 20;	//数组长度

struct  node {
    int  data;
    node* link;
};
node* createSortedLink()
{
    srand((unsigned int)time(NULL));
    node* head = NULL, * p, * q;
    int n = rand() % 20 - 10;   //n为有序链表的起点

    if (N == 0) return NULL;

    head = new node;
    p = head;
    p->data = n;
    p->link = NULL;

    for (int i = 1; i < N; i++) {
        q = new node;
        q->data = n + i * 1.5;  //要有点间隔
        q->link = NULL;
        p->link = q;
        p = q;
    }
    
    return head;
}

node* insertLink(node *head) {
    int num;
    cout << "请输入你想插入的数值（= -9999时退出）：";
    cin >> num;
    if (num == -9999) return head;

    int max;    //记录最大值
    node* m = head; //作为变量寻找尾结点
    while (m->link != NULL) {
        m = m->link;
    }
    max = m->data;  //由于我设置的链表顺序为升序，所以找到最后一个结点的值就行

    node* p = new node; //p是新结点
    p->data = num;

    if (num < head->data) { //插在头部
        p->link = head;
        head = p;
    }
    else if (num >= max) {   //如果大于等于最大值，插在最后面
        p->link = NULL;
        m->link = p;
    }
    else {  //在中间
        m = head;   //此时尾结点已经没有用了，以免重新创建其他变量
        while (m->link != NULL && m->link->data < p->data) { //找到要插入的位置，这种情况下，至少有2个结点
            m = m->link;
        }
        p->link = m->link;
        m->link = p;
    }

    return head;
}

void out_link(node* head)
{
    while (head != NULL)
    {
        cout << head->data << " --> ";
        head = head->link;
    }
    cout << endl;
}



int main()
{
    node* head;
    head = createSortedLink();
    out_link(head);
    head = insertLink(head);
    cout << "插入后：\n";
    out_link(head);
    return 0;
}
#endif
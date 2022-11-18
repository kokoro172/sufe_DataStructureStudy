#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 20;  //数组长度
struct  node {
    int  data;
    node* link;
};
node* createRandLink()
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
        q->data = rand()%40 - 20;  //随机数
        //q->data = (rand() % 10 - 5) * 2;    //全是偶数
        //q->data = (rand() % 10 - 5) * 2 + 1; //全是奇数
        q->link = NULL;
        p->link = q;
        p = q;
    }
    return head;
}

bool isOdd(int n) {
    return n % 2 == 1 || n % 2 == -1;
}

node* deleteOddNode(node* head) {
    if (head == NULL) { //链表为空时
        return head;
    }
    node* q = head;
    node* p = head;    //作用：指向要删除的结点的前面
    while (1) {
        if (isOdd(q->data)) { //删除的是头结点
            if (q->link == NULL) {//只剩头结点，且头结点为奇
                delete q;
                return NULL;   
            }
            
            head = q->link; //由于前面已经保存head结点，所以直接接上去，再删除
            delete(q);
            q = head;   //再接上去
        }
        else {  //删除的是中间结点，此时头结点已经为偶数，或者已经被删完并退出
            while (!isOdd(q->data) && q->link != NULL) {   //为了找到下一个匹配的结点
                p = q;
                q = q->link;
            }
            if (isOdd(q->data)) { //找到奇数
                p->link = q->link;  //接上去
                delete(q);  //删除该结点
                q = p;
            }
            else {  //是因为到尾了才停下来的
                return head;
            }
        }
    }
    
}

void out_link(node* head)
{
    if (head == NULL) cout << "链表为空\n";
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
    head = createRandLink();
    cout << "原链表：\n";
    out_link(head);

    head = deleteOddNode(head);
    cout << "删除后的链表：\n";
    out_link(head);
    return 0;
}

#endif
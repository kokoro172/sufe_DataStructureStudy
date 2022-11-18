#if 0
#include  <iostream>
using namespace  std;
/*带头结点的双向;链表的插入*/
struct node {
    int data;
    node* llink, * rlink;
};
node* head;
int insert_d_l(node* head, int x, int y)    //x:插在哪个数字之后，y：插什么值
{
    node* p, * q;
    p = head->rlink;
    while (p != head && p->data != x)
        p = p->rlink;
    if (p == head) return(1);
    q = new(node);
    q->data = y;
    q->rlink = p->rlink;
    p->rlink = q;
    q->rlink->llink = q;
    q->llink = p;
    return(0);
}

//为什么这个删除可以直接对数据操作，而之前的创建需要引用？
int delete_d_l(node* head, int x) /*带头结点的双向;链表的册除*/
{
    node* p;
    p = head->rlink;
    while (p != head && p->data != x)
        p = p->rlink;
    if (p == head) return(1);
    p->llink->rlink = p->rlink;
    p->rlink->llink = p->llink;
    delete  p;
    return(0);
}

node* create_link() {
    node* head = new node;
    head->data = -9999; head->llink = head; head->rlink = head; //头结点不是链表中的内容

    int n;
    cout << "请输入数据（-9999结束）：";
    cin >> n;
    if (n == -9999) {
        return head;
    }
    else if(head->llink == head) {
        node* q = new node;
        q->data = n;
        q->rlink = head; q->llink = head;
        head->llink = q; head->rlink = q;

        cout << "请输入数据（-9999结束）：";
        cin >> n;
    }
    
    while (n != -9999) {    //在头结点的左边插入新的结点
        node* q = new node, * p = head->llink;   //q：新结点，p：旧的尾结点
        q->data = n;
        q->rlink = head; q->llink = p;  //q连接两端
        p->rlink = q; head->llink = q;  //两端连接q
        
        cout << "请输入数据（-9999结束）：";
        cin >> n;
    }
    return head;
}

void output_link(node *head) {
    node* p = head->rlink;
    while (p->data != -9999) {
        cout << p->data << " --> ";

        p = p->rlink;
    }
    cout << "\n";
}

int main() {
    node* head;
    head = create_link();
    output_link(head);
    delete_d_l(head, 200);
    output_link(head);

}
#endif
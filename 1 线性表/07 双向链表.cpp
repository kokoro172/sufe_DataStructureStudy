#if 0
#include  <iostream>
using namespace  std;
/*带头结点的双向;链表的插入*/
struct NODE {
	int data;
	NODE* llink, * rlink;
};
NODE* head;

//NODE* createLink(NODE* head) {
//    if (head == NULL) {
//        head = new NODE;
//        cin >> head->data;
//
//    }
//}
NODE* createLink() {
	NODE* head = NULL;
	//head->data = -9999; head->llink = NULL; head->rlink = head; //头结点不是链表中的内容
	NODE* p, * q;
	int n;
	cout << "请输入数据（-9999结束）：";
	cin >> n;
	if (n == -9999) {
		return head;
	}
	else {
		head = new NODE;
		head->data = n;
		head->llink = NULL; //循环结点的话，此处为自己
		head->rlink = NULL; //同上
		p = head;
		cout << "请输入数据（-9999结束）：";
		cin >> n;
	}

	while (n != -9999) {
		q = new NODE;
		q->data = n; q->llink = p; q->rlink = NULL;
		p->rlink = q;
		p = q;  //尾结点更新
		cout << "请输入数据（-9999结束）：";
		cin >> n;
	}
	return head;
}

int insert_d_l(NODE* head, int x, int y)
{
	NODE* p, * q;
	p = head->rlink;
	while (p != head && p->data != x)
		p = p->rlink;
	if (p == head) return(1);
	q = new(NODE);
	q->data = y;
	q->rlink = p->rlink;
	p->rlink = q;
	q->rlink->llink = q;
	q->llink = p;
	return(0);
}

int delete_d_l(NODE* head, char x) /*带头结点的双向;链表的册除*/

{
	NODE* p;
	p = head->rlink;
	while (p != head && p->data != x)
		p = p->rlink;
	if (p == head) return(1);
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	delete  p;
	return(0);
}

void output_link(NODE* head) {
	NODE* p = head;
	while (p != NULL) {
		cout << p->data << " --> ";
		p = p->rlink;
	}
	cout << "\n";
}

int main() {
	NODE* q = createLink();
	output_link(q);
	return 0;
}
#endif
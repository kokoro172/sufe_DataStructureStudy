#if 0
#include  <iostream>
using namespace  std;
constexpr auto N = 10;  //链表大小
struct  node_one {
	int  data;
	node_one* link;
};

struct node_two {
	int  data;
	node_two* Llink;
	node_two* Rlink;
};

node_one* createRandLink()
{
	srand((unsigned int)time(NULL));
	node_one* head = NULL, * p, * q;
	int n = rand() % 20 - 10;   //n为有序链表的起点

	if (N == 0) return NULL;

	head = new node_one;
	p = head;
	p->data = n;
	p->link = NULL;

	for (int i = 1; i < N; i++) {   //生成结点数为N的链表
		q = new node_one;
		q->data = rand() % 40 - 20;  //随机数
		q->link = NULL;
		p->link = q;
		p = q;
	}
	return head;
}

node_two* oneToTwo(node_one* head) {
	node_one* p = head;
	node_two* tp = NULL, * tem = NULL, * thead = NULL;
	if (p != NULL) {
		thead = new node_two;   //开辟头结点
		thead->data = p->data;  //对头结点赋值
		thead->Llink = NULL;    //赋左link
		tp = thead; //尾指针指向头
		p = p->link;
	}
	while (p != NULL) {
		tem = new node_two; //新结点
		tem->Llink = tp; tem->Rlink = NULL; tem->data = p->data;    //对新结点赋值
		tp->Rlink = tem; tp = tem;   //连接上新结点，更新双向链表
		p = p->link;    //更新单向链表
	}
	return thead;
}

void printTwoLink(node_two* head) {
	node_two* p = head;
	while (p->Rlink != NULL) p = p->Rlink;
	cout << "逆序：\n";
	while (p != NULL) {
		cout << p->data << " <-> ";
		p = p->Llink;
	}
	cout << "\n";
}

void printOneLink(node_one* head) {
	node_one* p = head;
	while (p != NULL) {
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << "\n";
}

int main() {
	node_one* ohead = createRandLink();
	printOneLink(ohead);
	node_two* thead = oneToTwo(ohead);
	printTwoLink(thead);
}
#endif
#if 0
#include  <iostream>
using namespace  std;
struct  node {
	int  data;
	node* link;
};
node* create_link()
{
	int  n;
	node* head = NULL, * p, * q;
	p = head;

	cin >> n;
	while (n != -9999)
	{
		if (head == NULL) {
			head = new node;
			head->data = n;
			head->link = NULL;
			p = head;   //p只需要指向head即可
			cin >> n;   //还是需要一个cin，不然第一个就会创建两次
		}
		else {
			q = new node;   //用q创建，然后p再指
			q->data = n;
			q->link = NULL;
			p->link = q;
			p = q;
			cin >> n;
		}
		p->link = NULL;
	}

	return(head);
}

void out_link(node* head)
{
	while (head != NULL)
	{
		cout << head->data << "-->";
		head = head->link;
	}
	cout << endl;
}

node* reverse_link(node* head) {
	if (head == NULL || head->link == NULL) return head; //空表或者只有一个结点相当于不需要反转
	node* p = head->link;
	node* q = p->link;
	head->link = NULL;
	while (q != NULL) {
		p->link = head; //将“中间”结点指向上一个结点
		head = p;   //以下三句相当于把这三个指针整体向后移动一个
		p = q;
		q = p->link;    //p->link还是q->link都一样，用p->link为了方便理解
	}
	p->link = head; //最后一个结点还没有连到倒数第二个上面
	return p;
}

int main()
{
	node* head;
	head = create_link();
	cout << "原链表：\n";
	out_link(head);
	cout << "\n";

	head = reverse_link(head);
	cout << "反转后：\n";
	out_link(head);

	return 1;
}

#endif
#if 0
#include <iostream>
using namespace std;

struct node {
	int data;
	node* link;
};

//选择排序
void selectionSort(node *head) {
	node* p = head;//p用于往后遍历每一个元素
	node* q = head;	//q用于指向排好序的末尾的结点的后一个结点
	node* t = head;	//t用于指向最小元素

	p = q->link;
	while (q->link != NULL && p != NULL) {
		t = q;	//从q开始
		while (p != NULL) {	//往后遍历所有结点
			if (p->data < t->data) {	//如果找到了更小的元素
				t = p;//t指向最小元素
			}
			p = p->link;//继续向后遍历
		}//此时已经找到了最小的值所在的结点，由t指向

		if (t != q) {//最小值在后面的话，就交换两个结点的值
			/*int tem = t->data;
			t->data = q->data;
			q->data = tem;*/
			swap(t->data, q->data);
		}
		q = q->link;//排好序后，更新末尾结点
		p = q->link;//因为t指向q，所以p从q的下一个开始
	}
}

//此函数用于创建随机单链表
node* createRandLink()
{
	srand((unsigned int)time(NULL));
	node* head = NULL, * p, * q;
	int n = rand() % 20 - 10;   
	head = new node;
	p = head;
	p->data = n;
	p->link = NULL;

	for (int i = 1; i < 10; i++) {
		q = new node;
		q->data = rand() % 40 - 20;  //随机数
		q->link = NULL;
		p->link = q;
		p = q;
	}
	return head;
}

//此函数用于输出链表
void outPutLink(node *head) {
	node* p = head;
	while (p != NULL) {
		cout << p->data << " -> ";
		p = p->link;
	}
	cout << endl;
}

int main() {
	node* head = createRandLink();
	outPutLink(head);
	selectionSort(head);
	outPutLink(head);
}
#endif
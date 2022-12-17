#if 0
#include<iostream>
using namespace std;

struct  node {
	char  data;
	node* lchild, * rchild;
};
node* t, * p, * q;
char  a;

void search(node* t, char a, node*& p_p, node*& p_q)
{
	p_p = NULL;
	p_q = t;
	while (p_q != NULL)
	{
		if (p_q->data == a) return;
		p_p = p_q;
		if (a < p_q->data)
			p_q = p_q->lchild;
		else  p_q = p_q->rchild;
	}
	return;
}

int insert(node*& p_t, char a)
{
	node* p, * q, * r;
	search(p_t, a, p, q);
	if (q != NULL)  return(1);
	r = new node;
	r->data = a;
	r->lchild = NULL;
	r->rchild = NULL;
	if (p == NULL)  p_t = r;
	else if (p->data > a)
		p->lchild = r;
	else p->rchild = r;
	return(0);
}

int deleteNode(node*& p_t, char a)
{
	node* p, * q, * r;
	search(p_t, a, p, q);//q指向被删结点
	if (q == NULL) return(1);
	if (p == NULL) {//被删结点为根
		if (q->lchild == NULL)
			p_t = q->rchild;
		else {
			r = q->lchild;
			while (r->rchild != NULL)
				r = r->rchild;

			r->rchild = q->rchild;
			p_t = q->lchild;
		}
	}
	else if (q->lchild == NULL) {
		if (q == p->lchild)
			p->lchild = q->rchild;
		else p->rchild = q->rchild;
	}
	else {
		r = q->lchild;
		while (r->rchild != NULL)
			r = r->rchild;
		r->rchild = q->rchild;

		if (q == p->lchild)
			p->lchild = q->lchild;
		else
			p->rchild = q->lchild;
	}
	delete(q);
	return(0);
}

void midOrder(node* head) {
	if (!head) return;
	midOrder(head->lchild);
	cout << head->data << " ";
	midOrder(head->rchild);
}
int main() {
	node* tree = NULL;
	char a[] = "absdfla";
	for (int i = 0; i < 7; i++) {
		insert(tree, a[i]);
	}
	midOrder(tree);
}
#endif
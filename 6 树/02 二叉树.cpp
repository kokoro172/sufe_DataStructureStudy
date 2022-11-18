#if 0
# include <iostream>
using namespace std;
#define MAXN 100
struct node {
	char data;
	node* Ichild;
	node* rchild;
};
struct lrnode {
	char data;
	char flag, rtag;
};
node* transfer(lrnode  tree[], int n)
{
	node* stack[MAXN], * root, * p, * q;
	int top, i;
	if (n == 0) return(NULL);
	root = new  node;
	p = root;
	top = 0;
	for (i = 0; i < n - 1; i ++)
	{
		p->data = tree[i].data;
		if (tree[i].rtag == '0')
			stack[top++] = p;
		else p->rchild = NULL;
		q = new node;
		if (tree[i].rtag == '0')
			p->Ichild = q;
		else {
			p->Ichild = NULL;
			p = stack[--top];
			p->rchild = q;
		}
		p = q;
	}
	p->data = tree[n - 1].data;
	p->Ichild = NULL;
	p->rchild = NULL;
	return(root);
}
void preorder(node* t) {
	if (t == NULL)return;
	cout << t->data << " ";
	preorder(t->Ichild);
	preorder(t->rchild);
}

int main() {

}
#endif
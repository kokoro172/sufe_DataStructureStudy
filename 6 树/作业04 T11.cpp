#if 0
# include <iostream>
# include <stack>
using namespace std;
#define MAXN 100
struct node {
	char data;
	node* lchild;	//指向左子结点
	node* rchild;	//指向右子结点
};
struct lrnode {
	char data;
	char ltag, rtag;	//值为0说明有对应的结点，为1说明没有
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
			stack[top++] = p;	//入栈
		else 
			p->rchild = NULL;

		q = new node;

		if (tree[i].ltag == '0')
			p->lchild = q;
		else {
			p->lchild = NULL;
			p = stack[--top];	//出栈
			p->rchild = q;
		}

		p = q;
	}
	p->data = tree[n - i].data;
	p->lchild = NULL;
	p->rchild = NULL;
	return(root);
}

// 找到父节点。
// 可以通过栈来模拟向二叉树的转化，从而得出父节点
lrnode* findFatherNode(lrnode tree[], char a, int length) {	//传入的变量为：附加2个标志位储存的树，结点a的值，树的结点数
	stack<lrnode*> treeStk;
	if (tree == NULL || tree[0].data == a) {
		cerr << "找不到父节点！\n";
		return NULL;	//如果树不存在或者没有父节点，返回空；
	}

	int i = 0;
	for (; i < length; i++) {	///模拟建树
		if (tree[i].data == a) break;	//找到了
		if (tree[i].rtag == '0') 
			treeStk.push(&tree[i]);	//如果它存在右子结点，就入栈

		if (tree[i].ltag == '1')	//如果这个结点没有左子结点，说明下一个结点就是某个结点的右子结点
			treeStk.pop();
	}

	if (i == length || i == 0) {	//没有找到值为a的结点
		cerr << "没有找到值为a的结点或为根结点！\n";
		return NULL;
	}
	else {
		if (tree[i - 1].ltag == '0') //说明这个结点是上个结点的子结点
			return &tree[i - 1];
		else if (!treeStk.empty())	//如果栈不空（数组可能有错）
			return treeStk.top();	//如果上一个结点没有左子结点，说明这个结点的父节点在栈中
		else
			return NULL;
	}
}

//根据数组创建树，从左到右：
//树，树的结点数，数据数组，左标志位数组，右标志位数组
void makeTree(lrnode tree[], int n, char dataA[], char ltagA[], char rtagA[]) {
	for (int i = 0; i < n; i++) {
		tree[i].data = dataA[i];
		tree[i].ltag = ltagA[i];
		tree[i].rtag = rtagA[i];
	}
}
int main() {
	lrnode tree[MAXN];
	char dataA[] = "ABDFCEGH";
	char ltagA[] = "01010011";
	char rtagA[] = "00111101";

	char a = 'G';

	makeTree(tree, 8, dataA, ltagA, rtagA);
	lrnode *tem = findFatherNode(tree, a, 8);
	if (tem != NULL) {	// 若返回值为空，说明有错
		cout << "父节点的地址：" << tem << endl;
		cout << "父节点的值：" << tem->data << endl;
	}
	else
	{
		cerr << "有错！请修改！\n";
	}
}
#endif
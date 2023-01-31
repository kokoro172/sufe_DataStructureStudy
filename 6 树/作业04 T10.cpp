#if 0
#include<iostream>
constexpr int MAXN = 100;
using namespace std;

//以前序形式存放结点附加左标志位和右指针，以结构体数组的形式储存树
struct node {
	char data;	// 结点的值
	int ltag;	// 如果它等于0，说明它后面是左子树。如果等于1，则表示它没有左子结点
	int rchild;	// 右子结点的位置，如果它为-1，则说明它没有右节点
};

// 标准形式储存的二叉树
struct bnode {
public:
	char data;	//值
	bnode* lbnode;	//左结点
	bnode* rbnode;	//右结点
};

void createPreTree(node tree[]) {
	char ndata[] = "abdfghce";
	int nltag[] = { 0,0,1,0,1,1,1,1 };
	int nrchild[] = { 6,-1,3,5,-1,-1,7,-1 };
	for (int i = 0; i < 8; i++) {
		tree[i].data = ndata[i];
		tree[i].ltag = nltag[i];
		tree[i].rchild = nrchild[i];
	}
}

//给它赋值，如果没开辟空间就开辟
void createBNode(bnode*& bhead, char c, bnode* l, bnode* r) {
	if (bhead == NULL)
		bhead = new bnode;
	bhead->data = c;
	bhead->lbnode = l;
	bhead->rbnode = r;
}

//附加左标志位和右指针 转化为 标准形式储存
bnode* convertPreToBin(int pos, node tree[]) {
	bnode* bhead = new bnode;
	bhead->data = tree[pos].data;	//对该结点赋值

	if (tree[pos].ltag && tree[pos].rchild == -1) {	//左右都为空
		bhead->lbnode = NULL;
		bhead->rbnode = NULL;
		return bhead;
	}
	if (!tree[pos].ltag) {	// 左子结点存在
		bhead->lbnode = convertPreToBin(pos + 1, tree);	//后面一个就是左子结点
	}
	if (tree[pos].rchild != -1) {	//右子结点存在
		bhead->rbnode = convertPreToBin(tree[pos].rchild, tree);	//跳到右子结点的位置
	}
	return bhead;
}

int main() {
	node tree[MAXN];
	createPreTree(tree);

	bnode* head = convertPreToBin(0, tree);
	cout << tree[0].data;
}
#endif
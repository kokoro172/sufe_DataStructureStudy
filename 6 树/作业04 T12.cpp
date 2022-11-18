#if 0
#include<iostream>
using namespace std;

struct node {	//穿线树
	char data;	//值
	int ltag = 0, rtag = 0; //当ltag = 0时，lchild指向它的左子结点；当ltag = 1时，lchild指向它对应顺序（比如中序）的前一个值的结点
	node* lchild, * rchild;	
};

//将中序穿线树以前序方式输出
void prePrint(node* head) {
	while(head != NULL){
		cout << head->data << " ";
		if (head->ltag == 0 && head->lchild) {	//一直往左跑，跑到底。（如果左子结点存在且不为空）
			head = head->lchild;
			continue;
		}

		if (head->ltag == 1 || head->lchild == NULL) {
			while (head->rchild != NULL && head->rtag != 0)	//往“回”跑，跑到有右结点的地方
				head = head->rchild;
			head = head->rchild;	//接着到这个右结点这里
		}
	}
}

//void prePrint(node* head) {
//	while (head != NULL) {
//		cout << head->data << " ";
//		if (head->ltag == 1 || head->lchild == NULL) {
//			head = head->lchild;
//			continue;
//		}
//		else {
//			head = head->lchild;
//			while (head->rtag == 0)
//				head = head->rchild;
//		}
//	}
//}


//由于如果有重复数值可能会有多种情况，所以我们这里假设没有重复数值
//前序的第一个为根节点，中序的根节点左右方分别是左右子树，所以可以利用这一点递归
node* makeTreeByPreIno(char pre[], char ino[], int n) {	//传入的两个参数分别为：前序、中序、数组长度
	if (n == 0) {	//当数组长度为0时，返回NULL
		return NULL;
	}

	// 1.首先取前序的首个作为根节点的值
	node* head = new node;
	head->data = pre[0];

	// 2.接着在中序里面找到这个值
	char* p = ino;	//作为寻找该值的指针
	for (; p < ino + n; p++) {
		if (*p == pre[0])	//找到根节点的位置（值不重复）
			break;
	}

	int leftNum = p - ino;	//左子树的大小，等于中序里面找到的根节点的位置减去开头的位置

	// 3.找到后，它（中序）的左边为左子树，右边为右子树，开始递归

	// 首先是左子树，pre[0]已经是根节点了，所以需要“后移”一位
	// 中序的“子树范围”受leftNum（左子树大小）限制，所以相当于ino和leftNum一起“截取”了该子树
	head->lchild = makeTreeByPreIno(pre + 1, ino, leftNum);

	// 接着是右子树，它的起始位置等于起点加左子树的大小。
	// 右子树的起点则为p+1，长度为总长减去左子树长（找到的根节点后面的部分）
	// 而长度则为剩下一部分的长度（传入的长度减一，因为前序的第一个已经是根节点了，所以总长度减一）减去左子树长度
	head->rchild = makeTreeByPreIno(pre + 1 + leftNum, p + 1, n - leftNum - 1);

	return head;
}

//将二叉树（中序）线索化
//pre指向前一个结点
void createTree(node* head, node* &pre) {
	if (head) {
		createTree(head->lchild, pre);

		if (!head->lchild) {	//如果左孩子为空
			head->ltag = 1;	//标记为：没有左孩子
			head->lchild = pre;	//左孩子赋值为前继
		}

		if (pre != NULL && !pre->rchild) {	//如果右孩子为空
			pre->rtag = 1;	//标记为：没有右孩子
			pre->rchild = head;	//指向后继
		}

		pre = head;
		createTree(head->rchild, pre);
	}
}

int main() {
	char a[] = "ABDGCEF";	//前序
	char b[] = "GDBAECF";	//中序
	node *head = makeTreeByPreIno(a, b, 9), *pre = NULL;


	createTree(head, pre);
	head->rchild->rchild->rchild = NULL;
	//pre = NULL;	//对最后一个结点线索化


	//if (!pre) cout << "寄\n";
	prePrint(head);
	return 0;
}
#endif
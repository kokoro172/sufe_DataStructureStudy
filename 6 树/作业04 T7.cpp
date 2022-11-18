#if 0
#include<iostream>
using namespace std;

struct node {
	char data;
	node* leftChild;	//左子结点
	node* rightChild;	//右子结点
};


void printBinaryTree(node* head) {
	if (head == NULL) {	//某结点为空，返回
		return;
	}

	//树T的后序对应T'的中序
	printBinaryTree(head->leftChild);
	cout << head->data << " ";
	printBinaryTree(head->rightChild);
}



//t7，利用二叉树的前序和中序建立树
// https://weibaohang.blog.csdn.net/article/details/110233951?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-110233951-blog-105255475.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-110233951-blog-105255475.pc_relevant_default&utm_relevant_index=1
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
	head->leftChild = makeTreeByPreIno(pre + 1, ino, leftNum);	

	// 接着是右子树，它的起始位置等于起点加左子树的大小。
	// 右子树的起点则为p+1，长度为总长减去左子树长（找到的根节点后面的部分）
	// 而长度则为剩下一部分的长度（传入的长度减一，因为前序的第一个已经是根节点了，所以总长度减一）减去左子树长度
	head->rightChild = makeTreeByPreIno(pre + 1 + leftNum, p + 1, n - leftNum - 1);	

	return head;
}

bool isCompleteBT(node* head) {
	if (head->leftChild == NULL && 
		head->rightChild == NULL) {	//左右子树均为空，说明是叶子结点，返回真
		return true;
	}
	else if (head->leftChild != NULL && head->rightChild != NULL) {	//如果左右子树均不为空，递归下去
		return isCompleteBT(head->leftChild) && isCompleteBT(head->rightChild);	
	}
	else
		return false;	//一个为空，一个不为空，不是完全二叉树
}


int main() {
	node* head = NULL;

	char pre[] = "abdgcef";
	char ino[] = "gdbaecf";

	head = makeTreeByPreIno(pre, ino, 7);

	cout << endl << isCompleteBT(head) << endl;
	printBinaryTree(head);	//期望输出：gdbaecf
}
#endif
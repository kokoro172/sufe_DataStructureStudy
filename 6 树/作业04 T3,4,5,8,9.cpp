#if 0
#include<iostream>
using namespace std;

struct node {
	int data;
	node* leftChild;	//左子结点
	node* rightChild;	//右子结点
};

//利用递归构造完全二叉树，n为层数
void makeBinaryTree(node* &head,int n) {

	if (n <= 0) {	//到底赋null
		head = NULL;
	}
	else {
		head = new node;
		head->data = rand() % 10;	//赋随机值
		makeBinaryTree(head->leftChild, n - 1);	//左
		makeBinaryTree(head->rightChild, n - 1);	//右
	}
	
}

//利用栈（即递归）实现后序遍历
//后序
void printBinaryTree(node* head) {
	if (head == NULL) {	//某结点为空，返回
		return;
	}

	//树T的后序对应T'的中序
	printBinaryTree(head->leftChild);	
	cout << head->data << " ";
	printBinaryTree(head->rightChild);
}

//交换结点
void swapBinaryTree(node* &head) {
	if (head == NULL) return;
	swap(head->leftChild, head->rightChild);	//先换上面的，把它移到最下面也可以
	swapBinaryTree(head->leftChild);
	swapBinaryTree(head->rightChild);
}

//计算叶子结点的数量
//树的叶子结点数量为转化成二叉树后的左结点为空的数量
void coutChild(node* head) {
	
	if (head == NULL) return;
	if (head->leftChild == NULL)	//左孩子为空就加一
		cout << head->data << " ";
	coutChild(head->leftChild);	//本结点的叶子结点数量等于它左右两个结点的和
	coutChild(head->rightChild);
	return;
}

//计算当前结点的最大右连续子结点
int countConRight(node* head) {
	int sum = 1;
	if (head->rightChild != NULL)
		sum += countConRight(head->rightChild);
	else
		return sum;

}

//计算树的次数
//树的次数就是二叉树的左孩子的连续右孩子（包括自己）的最大值
int countTimes(node* head) {
	if (head == NULL) return 0;
	int num = countConRight(head);

	//计算当前结点的最大连续值
	//跟左右孩子的比较,取最大值
	num = max(max(countTimes(head->rightChild),countTimes(head->leftChild)),num);
	return num;
}

//判断是不是完全二叉树
bool isCompleteBT(node* head) {
	if (head->leftChild == NULL && head->rightChild == NULL) {	//左右子树均为空，说明是叶子结点，返回真
		return true;
	}
	else if (head->leftChild != NULL && head->rightChild != NULL) {
		return isCompleteBT(head->leftChild) && isCompleteBT(head->rightChild);	//如果左右子树均不为空，递归下去
	}
	else
		return false;	//一个为空，一个不为空，不是完全二叉树
}

//判断两树是否相似
bool isSimilarTree(node* tree1, node* tree2) {
	if (tree1 == NULL && tree2 == NULL)
		return true;
	else if (tree1 != NULL && tree2 != NULL)
		return isSimilarTree(tree1->leftChild, tree2->leftChild)
		&& isSimilarTree(tree1->rightChild, tree2->rightChild);	//左右子树是否分别相似
	else
		return false;
}

int main() {
	srand((unsigned int)time(NULL));
	node* head = NULL, * head2 = NULL;
	
	// 计算次数测试
	makeBinaryTree(head, 8);
	head->rightChild = NULL;
	head->leftChild->leftChild = NULL;
	head->leftChild->rightChild->rightChild->leftChild = NULL;
	head->leftChild->rightChild->rightChild->rightChild = NULL;
	head->leftChild->rightChild->leftChild->leftChild = NULL;
	head->leftChild->rightChild->leftChild->rightChild->leftChild = NULL;
	head->leftChild->rightChild->leftChild->rightChild->rightChild->leftChild = NULL;

	printBinaryTree(head);
	cout << "\n";
	cout << countTimes(head);
}

///*char pre[] = "abdgcef";
//char ino[] = "gdbaecf";
//makeBinaryTree(head,3);
//makeBinaryTree(head2, 3);*/
////cout << isSimilarTree(head, head2) << endl;
////printBinaryTree(head);
////makeBinaryTree(head, 4);
///*printBinaryTree(head);
//cout << "\n";
//
//head->rightChild = NULL;
//head->leftChild->rightChild = NULL;
//
//printBinaryTree(head);
//cout << "\n";
//coutChild(head);*/
//
////cout << countTimes(head);
//
////swapBinaryTree(head);
////printBinaryTree(head);


#endif
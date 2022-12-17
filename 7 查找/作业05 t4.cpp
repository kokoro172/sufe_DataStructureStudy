#if 1
#include<iostream>
using namespace std;

struct node {
	int num;		//值
	node* left;	//左指针
	node* right;	//右指针
};

/**
 * . 构造满树
 * 
 * \param head 要构造的二叉树的根结点
 * \param n 树的层数
 */
void makeBinaryTree(node*& head, int n) {
	if (n <= 0) {	//到底赋null
		head = NULL;
	}
	else {
		head = new node;
		head->num = rand() % 10;	//赋随机值
		makeBinaryTree(head->left, n - 1);	//左
		makeBinaryTree(head->right, n - 1);	//右
	}
}

/**
 * . 利用递归计算树的高度。当前结点的高度 = 子树最大高度 + 1
 * 
 * \param head	头结点
 * \return 返回当前结点的高度
 */
int countHeight(node* head) {
	if (head->left == NULL && head->right == NULL) {		//如果为叶子结点
		return 1;
	}
	else if (head->left == NULL) {
		return countHeight(head->right) + 1;
	}
	else if (head->right == NULL) {
		return countHeight(head->left) + 1;
	}
	else {
		return max(countHeight(head->left), countHeight(head->right)) + 1;	//返回左右最高 + 1
	}
}

int main() {
	node* head = NULL;
	makeBinaryTree(head,5);
	head->left->left = NULL;
	head->left->right = NULL;
	head->right->left = NULL;
	//head->right->right = NULL;

	cout << countHeight(head);
}

#endif
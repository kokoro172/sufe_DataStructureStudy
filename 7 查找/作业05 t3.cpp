#if 0
#include<iostream>
using namespace std;

struct node {
	int num;		//值
	node* left;	//左指针
	node* right;	//右指针
};

/**
 * .递归地判断是不是二叉查找树
 *
 * \param head 传入的根结点
 * \return
 */
bool isBST(node* head) {
	if (head->left == NULL && head->right == NULL) {	//全为空
		return true;
	}
	else if (head->left == NULL) {		//右不为空
		return head->num < head->right->num&& isBST(head->right);	//右子树为查找树而且右大于左
	}
	else if (head->right == NULL) {	//左不为空
		return head->num > head->left->num && isBST(head->left);
	}
	else {	//左右都不空
		return head->left->num < head->num&&		//左小于中
			head->num < head->right->num&&	//中小于右
			isBST(head->left) && isBST(head->right);	//左右都是
	}
}

int main() {
	node* head = new node;
	node* l = new node; node* r = new node;
	head->left = l; head->right = r; head->num = 9;
	l->left = l->right = NULL; l->num = 8;
	r = NULL;
	//r->left = r->right = NULL; r->num = 10;

	cout << isBST(head);
}
#endif
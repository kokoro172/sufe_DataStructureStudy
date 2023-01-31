#if 0
#include<iostream>
#include<stack>
using namespace std;

//node的结构
struct node {
	int data;
	node* leftChild;	//左子结点
	node* rightChild;	//右子结点
};

void stackPrintTree(node* head) {
	if (!head) return;
	stack<node*> bs;
	bs.push(head);	// 压入根结点

	node* p = head;	// 

	while (!bs.empty()) {
		head = bs.top();

	}
}

int main() {

}
#endif
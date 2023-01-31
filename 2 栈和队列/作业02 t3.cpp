#if 0
#include<iostream>
using namespace std;

struct node {
	int data;
	node* link;
};

class  STACK {
public:
	node* top = NULL;
	int push(int a);
	int pop(int& a);
	void printS();
};

int STACK::push(int a) {
	if (top == NULL) {
		top = new node;
		top->data = a;
		top->link = NULL;
		return 0;
	}
	else {
		node* p = new node;
		p->data = a; p->link = top;	//接到开头
		top = p;
		return 0;
	}
	return 1;	//插入失败
}

int STACK::pop(int& a) {
	if (top == NULL) return 1;
	node* p = top;
	top = top->link; a = p->data;
	delete p;
	return 0;
}

void STACK::printS() {
	node* p = top;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << "\n";
}

int main() {
	STACK s;
	for (int i = 0; i < 9; i++) {
		if (s.push(i))
			cout << "入栈失败！\n";
	}
	s.printS();
	int a;
	s.pop(a);
	cout << "pop: " << a << endl;
	s.printS();
	return 0;
}
#endif
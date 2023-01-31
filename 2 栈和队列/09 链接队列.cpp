#if 0
#include  <iostream>
using namespace  std;
struct NODE {
	char data;
	NODE* link;
};
NODE* head, * tail;

void en_queue_l(char x)
{
	NODE* p;
	p = new(NODE);
	p->data = x;
	p->link = NULL;
	if (head == NULL)
		head = p;
	else
		tail->link = p;
	tail = p;
}
int de_queue_l(char& p_y)
{
	NODE* p;
	if (head == NULL)
		return(1);
	p_y = head->data;
	p = head;
	head = head->link;
	delete p;
	return(0);
}

void print_queue() {
	NODE* p = head;
	if (p == NULL)
		return;
	while (p != NULL) {
		cout << p->data << "->";
		p = p->link;
	}
	cout << "\n";
}

int main() {
	char a;
	for (int i = 0; i < 7; i++) {
		cin >> a;
		en_queue_l(a);
	}
	print_queue();
	de_queue_l(a);
	print_queue();
	return 0;
}
#endif
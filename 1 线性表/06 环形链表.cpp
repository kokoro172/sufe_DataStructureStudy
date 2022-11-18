#if 0
#include<iostream>
using namespace std;

struct NODE {
	int data;
	NODE* link;
};

NODE* create_link()
{
    int n;
    NODE* head = NULL, * p, * q;    //q:创建新结点，p:指向尾结点
    p = head;
    cin >> n;
    while (n != -9999)
    {
        if (head == NULL) {
            head = new NODE;
            head->data = n;
            head->link = head;
            p = head;   
            cin >> n;   
        }
        else {
            q = new NODE;   
            q->data = n;
            q->link = head;
            p->link = q;
            p = q;
            cin >> n;
        }
        p->link = head;
    }
    return(head);
}

void out_link(NODE* head)
{
    NODE* point = head;
    cout << head->data << "-->";
    point = point->link;
    while (point != head)
    {
        cout << point->data << "-->";
        point = point->link;
    }
    cout << endl;
}


int main() {
    NODE* h = NULL;
    h = create_link();
    out_link(h);
    return 0;
}
#endif
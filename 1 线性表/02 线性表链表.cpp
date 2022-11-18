#if 0
#include  <iostream>
using namespace  std;
struct  NODE {
    int  data;
    NODE* link;
};
NODE* create_link(/*int n*/)
{
    int /*i,*/ n;
    NODE* head = NULL, * p, * q;
    p = head;
    //if (n == 0) return(NULL);
    cin >> n;
    while (n != -9999)/*for (i = 1; i < n; i++)*/
    {
        if (head == NULL) {
            head = new NODE;
            head->data = n;
            head->link = NULL;
            p = head;   //p只需要指向head即可
            cin >> n;   //还是需要一个cin，不然第一个就会创建两次
        }
        else{
            q = new NODE;   //用q创建，然后p再指
            q->data = n;
            q->link = NULL;
            p->link = q;
            p = q;
            cin >> n;
        }
        p->link = NULL;
    }
    //cin >> p->data;
    
    return(head);
}

void insert_link(NODE *head) {
    int loc;
    cout << "Where do you want to insert?\n";
    cin >> loc;
    loc -= 1;
    NODE* pos = head;
    
    //about head
   /* if (loc == -1) {
        int num;
        cout << "please input the number\n";
        cin >> num;
        NODE* q = new NODE;
        q->data = num;
        q->link = head;
        head = q;
    }*/

    //insert
    int num;
    cout << "please input the number\n";
    cin >> num;
    NODE* q = new NODE;
    q->data = num;
    if (loc == -1) {    //problem: 无法同步，传递的不是指针吗？
        q->link = head;
        head = q;   //为什么它不会改变？传递的是指针，必须要引用指针？
    }
    else {
        //find the position
        while (pos->link != NULL && loc) {  //为什么它不等于NULL，因为↓
            pos = pos->link;                         //不可以直接用pos++
            loc--;
        }
        q->link = pos->link;
        pos->link = q;
    }
    return;//head;
}

void out_link(NODE* head)
{
    while (head != NULL)
    {
        cout << head->data << "-->";
        head = head->link;
    }
    cout << endl;
}

NODE* delete_link(NODE* head, int a) {
    if (head == NULL) { //链表为空时
        cout << "链表为空！\n";
        return head;
    }
    NODE* q = head;
    if (q->data == a) { //删除的是头结点
        head = q->link; //由于前面已经保存head结点，所以直接接上去，再删除
        delete(q);
        return head;
    }
    else {  //删除的是中间结点
        NODE* p = head;    //作用：指向要删除的结点的前面
        while (q->data != a && q->link != NULL) {   //为了找到匹配的结点
            p = q;
            q = q->link;
        }
        if (q->data == a) { //是因为找到了才停下来的
            p->link = q->link;  //接上去
            delete(q);  //删除该结点
            return head;
        }
        else {  //是因为到尾了才停下来的
            cout << "未找到对应的结点！\n";
            return head;
        }
    }
}



int main()
{
    NODE* head;
    head = create_link();
    out_link(head);
    insert_link(head);
    out_link(head);

    delete_link(head, 5);
    out_link(head);
    return 1;
}

#endif
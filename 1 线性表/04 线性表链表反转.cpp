//#include  <iostream>
//using namespace  std;
//struct  NODE {
//    int  data;
//    NODE* link;
//};
//NODE* create_link()
//{
//    int /*i,*/ n;
//    NODE* head = NULL, * p, * q;
//    p = head;
//    //if (n == 0) return(NULL);
//    cin >> n;
//    while (n != -9999)/*for (i = 1; i < n; i++)*/
//    {
//        if (head == NULL) {
//            head = new NODE;
//            head->data = n;
//            head->link = NULL;
//            p = head;   //p只需要指向head即可
//            cin >> n;   //还是需要一个cin，不然第一个就会创建两次
//        }
//        else {
//            q = new NODE;   //用q创建，然后p再指
//            q->data = n;
//            q->link = NULL;
//            p->link = q;
//            p = q;
//            cin >> n;
//        }
//        p->link = NULL;
//    }
//    //cin >> p->data;
//
//    return(head);
//}
//
//void* insert_link(NODE*& head) {
//    int loc;
//    cout << "Where do you want to insert?\n";
//    cin >> loc;
//    loc -= 1;
//    NODE* pos = head;
//
//    //insert
//    int num;
//    cout << "please input the number\n";
//    cin >> num;
//    NODE* q = new NODE;
//    q->data = num;
//    if (loc == -1) {    
//        q->link = head;
//        head = q;   
//    }
//    else {
//        //find the position
//        while (pos->link != NULL && loc) {  
//            pos = pos->link;                        
//            loc--;
//        }
//        q->link = pos->link;
//        pos->link = q;
//    }
//    return head;
//}
//
//void out_link(NODE* head)
//{
//    while (head != NULL)
//    {
//        cout << head->data << "-->";
//        head = head->link;
//    }
//    cout << endl;
//}
//
//NODE* reverse_link(NODE* head) {
//    if (head == NULL || head->link == NULL) return head; //空表或者只有一个结点相当于不需要反转
//    NODE* p = head->link;
//    NODE* q = p->link;
//    head->link = NULL;
//    while (q != NULL) { 
//        p->link = head; //将“中间”结点指向上一个结点
//        head = p;   //以下三句相当于把这三个指针整体向后移动一个
//        p = q;
//        q = p->link;    //p->link还是q->link都一样，用p->link为了方便理解
//    }
//    p->link = head; //最后一个结点还没有连到倒数第二个上面
//    return p;
//}
//
//
//NODE* delete_link(NODE* head, int a) {
//    if (head == NULL) { //链表为空时
//        cout << "链表为空！\n";
//        return head;
//    }
//    NODE* q = head;
//    if (q->data == a) { //删除的是头结点
//        head = q->link; //由于前面已经保存head结点，所以直接接上去，再删除
//        delete(q);
//        return head;
//    }
//    else {  //删除的是中间结点
//        NODE* p = head;    //作用：指向要删除的结点
//        while (q->data != a && q->link != NULL) {   //为了找到匹配的结点
//            p = q;
//            q = q->link;
//        }
//        if (q->data == a) { //是因为找到了才停下来的
//            p->link = q->link;  //接上去
//            delete(q);  //删除该结点
//            return head;
//        }
//        else {  //是因为到尾了才停下来的
//            cout << "未找到对应的结点！\n";
//            return head;
//        }
//    }
//}
//
//
//int main()
//{
//    NODE* head;
//    head = create_link();
//    out_link(head);
//    head = reverse_link(head);
//    //head = delete_link(head, 3);
//    //insert_link(head);
//    out_link(head);
//    return 1;
//}

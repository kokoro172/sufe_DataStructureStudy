//#include <iostream>
//#include<ctime>
//#include <Windows.h>
//using namespace std;
//
//const int n1 = 8;   //n为多项式1最高次
//const int n2 = 8;   //n为多项式2最高次
//
//struct  NODE {
//    int coef;
//    int exp;
//    NODE* link;
//};
//
//
//NODE* insert(NODE* pc, int c, int e)
//{
//    NODE* t;
//    t = new(NODE);
//    t->coef = c;
//    t->exp = e;
//    pc->link = t;
//    return(t);
//}
//
//
//NODE* create_randLink(NODE* link, int n) {
//    NODE *tail = link;
//    if (n == 0) return NULL;
//    if (link == NULL) {
//        link = new NODE;
//        link->coef = rand() % 20 - 10;
//        link->exp = n;
//        link->link = NULL;
//        tail = link;
//        n--;
//    }
//    else {  //找到尾巴
//        while (tail->link != NULL)
//            tail = tail->link;
//    }
//    srand((unsigned)time(NULL));
//    while(n--) {
//        NODE* t;
//        t = new NODE;
//        t->coef = rand() % 20 - 10;
//        t->exp = n;
//        t->link = NULL;
//        tail->link = t;
//        tail = t;
//    }
//    return link;
//}
//
//void outputLink(NODE* link) {
//    NODE* head = link;
//    if (head != NULL) {
//        cout << head->coef << "x^" << head->exp;
//        head = head->link;
//    }
//    while (head != NULL) {
//        if (head->coef == 0) {
//            head = head->link;
//            continue;
//        }
//        else if (head->coef > 0) {
//            if (head->exp == 0) {
//                cout << " + " << head->coef;
//            }
//            else {
//                cout << " + " << head->coef << "x" << "^" << head->exp;
//            }
//            head = head->link;
//        }
//        else{
//            if (head->exp == 0) {
//                cout << " " << head->coef;
//            }
//            else {
//                cout << " " << head->coef << "x" << "^" << head->exp;
//            }
//            head = head->link;
//        }
//        
//    }
//    cout << "\n";
//}
//
//
//
//NODE* polyadd_1(NODE* ah, NODE* bh)
//{
//    NODE* pa, * pb, * ch, * pc;
//    char c;
//    ch = new(NODE);
//    pc = ch;
//    pa = ah;
//    pb = bh;
//    while (pa != NULL && pb != NULL)
//    {
//        if (pa->exp == pb->exp) c = '=';    //没想到居然是因为老师的''中间有空格，所以无限循环
//        else if (pa->exp > pb->exp) c = '>';
//        else c = '<';
//        switch (c)
//        {
//        case  '=':
//            if (pa->coef + pb->coef != 0)
//                pc = insert(pc, pa->coef + pb->coef, pa->exp);
//            pa = pa->link;
//            pb = pb->link;
//            break;
//        case  '>':
//            pc = insert(pc, pa->coef, pa->exp);
//            pa = pa->link;
//            break;
//        case  '<':
//            pc = insert(pc, pb->coef, pb->exp);
//            pb = pb->link;
//            break;
//        }
//    }
//    while (pa != NULL)	//某一方到了底
//    {
//        pc = insert(pc, pa->coef, pa->exp);
//        pa = pa->link;
//    }
//    while (pb != NULL)
//    {
//        pc = insert(pc, pb->coef, pb->exp);
//        pb = pb->link;
//    }
//    pc->link = NULL;
//    pc = ch;
//    ch = ch->link;
//    delete pc;
//    return(ch);
//}
//
//
//int main() {
//    NODE* linkOne = NULL, *linkTwo = NULL, *linkTh = NULL;
//
//    linkOne = create_randLink(linkOne, n1);
//    outputLink(linkOne);
//    Sleep(1000);
//    linkTwo = create_randLink(linkTwo, n2);
//    outputLink(linkTwo);
//
//    linkTh = polyadd_1(linkOne, linkTwo);
//    outputLink(linkTh);
//    return 0;
//}
//

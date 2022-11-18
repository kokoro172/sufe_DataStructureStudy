#if 0
#include<iostream>
using namespace std;

struct node {
    int coef, exp;
    node* link;
};

node* createPoly(node *head, int num)
{
    if (head == NULL) {
        head = new node;
        head->coef = 0;
        head->exp = -1;
        head->link = head;
    }
    node* p = head, * q;   //p指向最后一个结点，q指向新的结点
    int n;
    cout << "请输入次数为："<< num << "的系数（输入-9999提前停止）：";
    cin >> n;
    while (n != -9999) {
        q = new node;
        q->coef = n;
        q->exp = num;
        q->link = head; //创建新结点q并对其赋值      

        p->link = q;
        p = q;  //将新结点接上
        
        num--;  //它的位置至关重要
        if (num < 0) break;
        cout << "请输入次数为：" << num << "的系数（输入-9999提前停止）：";
        cin >> n;
    }
    return head;
}

void outputPoly(node* head) {   //输出多项式
    bool isFirst = true;
    if(head->exp == -1) head = head->link;
    while(head->exp != -1) {  //执行完后，head为要输出的最后一个结点
        if (head->coef == 0) {
            head = head->link;
            continue;
        }
        else if (head->coef > 0 && head->exp != 0) {
            if (isFirst) {	//如果是多项式的第一项
                cout << head->coef << "x^" << head->exp;
                isFirst = false;
            }
            else {
                cout << " + " << head->coef << "x^" << head->exp;
            }
        }
        else if(head->coef < 0 && head->exp != 0) {
    		if (isFirst) {	//如果是多项式的第一项
    			cout << "-"<< -head->coef << "x^" << head->exp;	//由于负号和数字在一起不便于观察，便和正项统一格式
    			isFirst = false;
    		}
    		else {
    			cout << " - " << -head->coef << "x^" << head->exp;
    		}
        }
        else if (head->exp == 0) {  //应该可以直接else，不过保险起见，还是else if
            if (head->coef > 0) {
                if (isFirst) {
                    cout << head->coef;
                }
                else
                    cout << " + " << head->coef;
            }
            else if (head->coef < 0) {
                if(isFirst)
                    cout << -head->coef;
                else
                    cout << " - " << -head->coef;
            }
        }
        head = head->link;
    }
    cout << "\n\n";
}

void insertPoly(node*& c,int coef, int exp) {
    node* a = c;
    while (a->link->exp != -1) {
        a = a->link;
    }
    node* p = new node;
    p->coef = coef; p->exp = exp; p->link = c;
    a->link = p;
}

void addAndSubPoly(node*a, node*b, node*& c, node*& d) {    //使用指针引用
    if (a->exp = -1) a = a->link;   //防止传进来为头结点，然后无限循环
    if (b->exp = -1) b = b->link;

    while (a->exp != -1 && b->exp != -1) {  //a、b
        if (a->exp == b->exp) { //次数匹配
            insertPoly(c, a->coef + b->coef, a->exp);
            insertPoly(d, a->coef - b->coef, a->exp);

            a = a->link; b = b->link;   //下移
        }
        else if (a->exp > b->exp) {
            insertPoly(c, a->coef, a->exp);
            insertPoly(d, a->coef, a->exp);
            b = b->link;
        }
        else {  //a->exp < b->exp
            insertPoly(c, b->coef, b->exp);
            insertPoly(d, b->coef, b->exp);
            a = a->link;   //下移
        }
    }
    while (a->exp != -1)	//b到了底
    {
        insertPoly(c, a->coef, a->exp);
        insertPoly(d, a->coef, a->exp);
        a = a->link;
    }
    while (b->exp != -1)	//a到了底
    {
        insertPoly(c, b->coef, b->exp);
        insertPoly(d, b->coef, b->exp);
        b = b->link;
    }
}


int main() {
    node* ah = NULL, *bh = NULL;
    ah = createPoly(ah, 3);
    cout << "多项式a：\n";
    outputPoly(ah);

    bh = createPoly(bh, 3);
    cout << "\n多项式b：\n";
    outputPoly(bh);

    node* ch, * dh; //创建并初始化两个结果链表
    ch = new node; dh = new node;
    ch->link = ch; dh->link = dh;
    ch->exp = -1; dh->exp = -1;
    ch->coef = dh->coef = 0;

    addAndSubPoly(ah, bh, ch, dh);
    cout << "\na + b：\n";
    outputPoly(ch);
    cout << "\na - b：\n";
    outputPoly(dh);
    
    return 0;
}
#endif
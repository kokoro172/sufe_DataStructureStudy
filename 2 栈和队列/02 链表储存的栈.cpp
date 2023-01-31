#if 0
#include  <iostream>
using namespace  std;
struct NODE {
	char data;
	NODE* link;
};
NODE* top = NULL;
void push_l(char x) //入栈
{
	NODE* p;
	p = new(NODE);
	p->data = x;
	p->link = top;  //创建一个新结点，赋值并连接
	top = p;    //更换栈顶指针
}

int pop_l(char* p_y)    //出栈
{
	NODE* p;
	if (top == NULL)  return(1);    //如果栈空就不能出栈
	*p_y = top->data;
	p = top;    //保存栈顶的指针
	top = top->link;    //出栈
	delete p;   //回收原栈顶空间
	return(0);
}
#endif
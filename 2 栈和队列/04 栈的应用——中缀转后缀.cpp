#if 0
#include  <iostream>
using namespace std;
#define MAXN 100
char pos_e[MAXN];
int v[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };

//返回该运算符在栈中的优先级
int icp(char c)
{
    switch (c)
    {
    case '^':
        return(4);
    case '*':
    case '/':
        return(2);  //如果多个case条件后面的执行语句是一样的，那么该语句只需书写一次
    case '+':
    case '-':
        return(1);
    }
}


//返回该运算符在进栈前的优先级
int isp(char c)
{
    switch (c)
    {
    case '^':
        return(3);
    case '*':
    case '/':
        return(2);
    case '+':
    case '-':
        return(1);
    case '(':
        return(0);
    case '$':
        return(-1);
    }
}
/*
* 中缀转后缀函数
* mid_e: 中缀表达式
* pos_e: 后缀表达式
* 
* 转化规则：
* 是变量，立即输出
* 如果是左括号，直接入栈
* 如果是右括号，出栈，直到遇到第一个左括号
* 如果是 ^, +, -, *, /，比较栈中的优先级，若小于等于栈中的优先级，则出栈，否则进栈
* 如果是 \0 则全部出栈
*/

int mid_to_pos(char  mid_e[], char  pos_e[])
{
    char stack[MAXN], c;    
    int top, i, j;
    stack[0] = '$';
    top = 0;    // 表示栈顶的位置
    j = 0;  // 后缀表达式的第j项
    i = 0;  // 如下行
    c = mid_e[0];   // 储存表达式的第i项
    while (c != '\0')
    {
        if (islower(c)) // 非运算符进栈
            pos_e[j++] = c;
        else
            switch (c){
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while (icp(c) <= isp(stack[top])) //比较栈中的优先级，若小于等于栈中的优先级，则出栈
                        pos_e[j++] = stack[top--];
                    stack[++top] = c;
                    break;
                case '(':   //如果是 ( 就入栈
                    stack[++top] = c;
                    break;
                case  ')':  //如果是 ) ，则出栈，直到 ( 为止
                    while (stack[top] != '(')
                        pos_e[j++] = stack[top--];  //出栈的就填入后缀表达式
                    top--;  // 此时的stack[top]为( ，所以需要直接弹出，故top--
                    break;
                default:
                    return(1);
            }
        c = mid_e[++i];
    }
    while (top > 0) //剩下的直接弹出
        pos_e[j++] = stack[top--];
    pos_e[j] = '\0';
    return(0);
}

//计算后缀表达式
int  evaluate(char  pos_e[], int& p_y)
{
    int stack[MAXN];    // 作为栈来运算后缀表达式
    int top, i, x;  // x用于储存栈顶元素参与运算
    char c; // 储存表达式的第i项
    top = -1;   // 记录栈顶的位置值
    i = 0;  // 表达式的第几项
    c = pos_e[0];
    while (c != '\0')
    {
        if (islower(c)) // 如果是字母，就入栈对应的数字
            stack[++top] = v[c - 'a'];
        else
            // 如果是运算符，对于加减乘除，先保存栈顶元素的值，然后将栈顶两个元素进行对应的运算
            // 相当于把栈顶的两个元素经过相应运算融合成一个元素
            switch (c)
            {
            case '+':
                x = stack[top--];
                stack[top] += x;
                break;
            case '-':
                x = stack[top--];
                stack[top] -= x;
                break;
            case '*':
                x = stack[top--];
                stack[top] *= x;
                break;
            case '/':
                x = stack[top--];
                stack[top] /= x;
                break;
            case '^':
                int j, k, y, z;
                x = stack[top--];
                y = stack[top];
                if (y == 0)  return(1); // 如果底为0，认为这是错误的表达式
                if (x == 0) stack[top] = 1; // 如果幂为零，结果直接为1
                else {
                    if (x > 0) j = x;
                    else  j = -x;   // 取幂的绝对值

                    for (z = 1, k = 1; k <= j; k++) // 计算出结果
                        z *= y;

                    if (x < 0) z = 1 / z;   // 如果幂小于0，那么就变成1/n

                    stack[top] = z;
                }
                break;
            default: return(1);
            }
        c = pos_e[++i];
    }
    if (top > 0) return(1);
    p_y = stack[top];
    return(0);
}

int main()
{
    char mid_e[MAXN], pos_e[MAXN];   // 储存表达式，相当于string
    cout << "Please input a mid express?\n";
    cin >> mid_e;
    mid_to_pos(mid_e, pos_e);

    for (char ch : pos_e) { //输出生成的后缀表达式
        cout << ch;
        if (ch == '\0') break;  //不然会带乱码
    }
    cout << endl;
    int y; evaluate(pos_e, y);
    cout << "the result is: " << y << endl;
    
    return 0;
    
}
#endif
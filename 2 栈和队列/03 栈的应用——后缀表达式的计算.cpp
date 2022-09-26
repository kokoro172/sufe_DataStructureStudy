//#include  <iostream>
//using namespace std;
//#define MAXN 100
//
//int v[26] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26 };   //对应26个字母表示数字
//
///* 
//* 函数：evaluate(char pos_e[], int& p_y)
//* 作用：计算后缀表达式，字母在字母表中的序数代表数字，仅能用小写字母
//*/
//int  evaluate(char  pos_e[], int& p_y)
//{
//    int stack[MAXN];    // 作为栈来运算后缀表达式
//    int top, i, x;  // x用于储存栈顶元素参与运算
//    char c; // 储存表达式的第i项
//    top = -1;   // 记录栈顶的位置值
//    i = 0;  // 表达式的第几项
//    c = pos_e[0];
//    while (c != '\0')
//    {
//        if (islower(c)) // 如果是字母，就入栈对应的数字
//            stack[++top] = v[c - 'a'];
//        else
//            // 如果是运算符，对于加减乘除，先保存栈顶元素的值，然后将栈顶两个元素进行对应的运算
//            // 相当于把栈顶的两个元素经过相应运算融合成一个元素
//            switch (c)  
//            {
//            case '+':
//                x = stack[top--];
//                stack[top] += x;
//                break;
//            case '-':
//                x = stack[top--];
//                stack[top] -= x;
//                break;
//            case '*':
//                x = stack[top--];
//                stack[top] *= x;
//                break;
//            case '/':
//                x = stack[top--];
//                stack[top] /= x;
//                break;
//            case '^':
//                int j, k, y, z;
//                x = stack[top--];
//                y = stack[top];
//                if (y == 0)  return(1); // 如果底为0，认为这是错误的表达式
//                if (x == 0) stack[top] = 1; // 如果幂为零，结果直接为1
//                else{
//                    if (x > 0) j = x;
//                    else  j = -x;   // 取幂的绝对值
//                    
//                    for (z = 1, k = 1; k <= j; k++) // 计算出结果
//                        z *= y; 
//
//                    if (x < 0) z = 1 / z;   // 如果幂小于0，那么就变成1/n
//
//                    stack[top] = z; 
//                }
//                break;
//            default: return(1);
//            }
//        c = pos_e[++i];
//    }
//    if (top > 0) return(1);
//    p_y = stack[top];
//    return(0);
//}
//int  main()
//{
//    int y;  //用float还得大改代码，不能使用top--这种了，所以只能牺牲精度
//    char pos_e[MAXN];   // 储存表达式，相当于string
//    cout << "Please input a pos express?\n";
//    cin >> pos_e;
//    if (evaluate(pos_e, y))  cout << "Express is error!" << endl;
//    else cout << pos_e << "=" << y << endl;
//    return 0;
//}

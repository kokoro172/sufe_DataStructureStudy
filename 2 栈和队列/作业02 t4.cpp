//#include<iostream>
//#include<cctype>
//constexpr int MAXN = 100;
//using namespace std;
//
//int getPrior(char c) {
//    switch (c) {
//    case'>':
//        return 1;
//    case'+':
//    case'-':
//        return 2;
//    case'*':
//    case'/':
//        return 3;
//    case'^':
//        return 4;
//    case'(':
//        return 0;
//    }
//}
//
////根据传入的操作符对两个数进行运算，返回运算结果
//int getResult(char op, int a, int b) {
//    int sum = 1;
//    switch (op) {
//    case '+':
//        return a + b;
//    case '-':
//        return a - b;
//    case '*':
//        return a * b;
//    case '/':
//        if (b == 0) {   //除数为0则退出
//            cerr << "除数不能为0！\n";
//            exit(1);
//        }
//        return a / b;
//    case '%':
//        return a % b;
//    case '^':
//        for (int i = 0; i < b; i++) sum *= a;
//        return sum;
//    case '>':
//        return a > b;
//    default:
//        cerr << "存在不符合规则的运算符！\n";
//        exit(2);
//    }
//    return 0;
//}
//
//void countSum(char exp[], int& sum) {
//    int nstack[MAXN];char ostack[MAXN];
//    int ntop = -1, otop = -1;
//    int i = 0;  //遍历exp[]
//
//    while (exp[i] != '\0') {
//        if (isalpha(tolower(exp[i]))) { //是字母
//            // cout << "exp[" << i << "]= " << exp[i] << endl; //测试
//            ntop++;
//            nstack[ntop] = int(exp[i]) - 'a' + 1;   //转化成数字，压入栈内
//        }
//        else {       
//            switch (exp[i]) {
//            case '+':
//            case '-':
//            case '*':
//            case '/':
//            case '^':
//            case '%':
//                if (otop == -1) {   //如果操作符栈为空，直接压入栈
//                    otop++;
//                    ostack[otop] = exp[i];
//                }
//                else {
//                    if (getPrior(exp[i]) <= getPrior(ostack[otop])) {   //优先级低就计算栈内
//                        if (ntop <= 0||otop == -1) {    //表达式有误
//                            cerr << "表达式有误！\n";
//                            exit(1);
//                        }
//                        //计算栈内
//                        int tem = nstack[ntop];
//                        ntop--;
//                        nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);
//                        otop--; //操作符出栈
//                    }
//                    otop++; //入栈
//                    ostack[otop] = exp[i]; // 防止不断的推出操作符，最后空栈了;或者ch优先级高了
//                }
//                break;
//            case '(':   //入栈
//                otop++;
//                ostack[otop] = '(';
//                break;
//            case')':
//                while (ostack[otop] != '(') {
//                    if (ntop <= 0 || otop <= 0) {    //表达式有误
//                        cerr << "表达式有误！\n";
//                        exit(1);
//                    }
//                    int tem = nstack[ntop];
//                    ntop--; //取出操作数
//                    nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);  //计算结果，压入栈
//                    otop--; //操作符出栈
//                }
//                otop--; //把 ( 弹出
//                break;
//            }
//        }
//        i++;
//    }
//    while (otop > -1) {
//        if (ntop <= 0) {    //表达式有误
//            cerr << "表达式有误！\n";
//            exit(1);
//        }
//        int tem = nstack[ntop--];
//        nstack[ntop] = getResult(ostack[otop], nstack[ntop], tem);
//        otop--; //操作符出栈
//    }
//    if (ntop == 0) sum = nstack[ntop];
//    else {
//        cerr << "wrong！\n";
//        exit(1);
//    }
//}
//
//int main() {
//    char exp[MAXN];
//    int sum;
//
//    cout << "请输入表达式（26个字母分别对应1~26，请使用小写）:\n";
//    cin >> exp;
//    
//    countSum(exp, sum);
//    cout << sum << endl;
//}

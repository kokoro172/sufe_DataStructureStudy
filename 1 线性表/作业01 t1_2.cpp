#if 0
#include<iostream>
#include<ctime>
#include<Windows.h>
constexpr auto MAXSIZE = 10;;
using namespace std;



//说明：数组的序号为多项式的次数，数组每一项储存的数为该项的系数。
//即：a[0] 表示 系数为a[0]、次数为0 的项

//创建随机多项式
int* createRandPoly() {
	int* a = new int[MAXSIZE];
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAXSIZE; i++) {	//i为次数
		a[i] = rand() % 20 - 10;	//系数范围：-10~9
	}
	return a;
}

//手动输入系数
int* createPoly(int ap[]) {
	if(ap != NULL) 	delete[] ap;
	int coef, exp;
	int* a = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {	//首先初始化，全部设置为0，防止有没输入的项导致
		a[i] = 0;
	}
	cout << "请输入系数（为-9999时停止，是覆盖式输入）：";
	cin >> coef;
	while (coef != -9999) {
		cout << "请输入次数：";
		cin >> exp;
		while (exp >= MAXSIZE) {
			cout << "允许的次数范围为：0~" << MAXSIZE - 1 << "，请重新输入！\n";
			cout << "请输入次数：";
			cin >> exp;
		}
		a[exp] = coef;
		cout << "请输入系数（为-9999时停止）：";
		cin >> coef;
	}
	return a;
}

//相加
int* addPoly(int a[], int b[]) {
	int* c = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

//相减
int* subPoly(int a[], int b[]) {
	int* c = new int[MAXSIZE];
	for (int i = 0; i < MAXSIZE; i++) {
		c[i] = a[i] - b[i];
	}
	return c;
}

//输出多项式
void outputPoly(int a[]) {
    bool isFirst = true;
    for (int i = MAXSIZE - 1; i > 0; i--) {
        if (a[i] == 0) continue;
        else if (a[i] > 0) {
            if (isFirst) {	//如果是多项式的第一项
                cout << a[i] << "x^" << i;
                isFirst = false;
            }
            else {
                cout << " + " << a[i] << "x^" << i;
            }
        }
        else {
			if (isFirst) {	//如果是多项式的第一项
				cout << "-"<< -a[i] << "x^" << i;	//由于负号和数字在一起不便于观察，便和正项统一格式
				isFirst = false;
			}
			else {
				cout << " - " << -a[i] << "x^" << i;
			}
        }
    }
	
	if (a[0] > 0) {
		cout << " + " << a[0];
	}
	else if (a[0] < 0) {
		cout << " - " << -a[0];
	}
	cout << "\n\n";
}



int main() {
	int* a_poly = NULL, * b_poly = NULL;
	int* c_poly = NULL;

	int a, b;
	cout << "对于多项式a，你选择：\n";
	cout << "1. 手动创建\n";
	cout << "2. 随机创建(default)\n";
	cin >> a;

	if (a == 1) {
		cout << "请输入多项式a（最高次数为：" << MAXSIZE - 1 << "次）：\n";
		a_poly = createPoly(a_poly);
	}
	else {	//默认随机
		a_poly = createRandPoly();	//随机创建多项式
	}
	
	cout << "\n多项式a：\n";
	outputPoly(a_poly);

	Sleep(1000);	//停顿一秒，防止随机数一样

	cout << "对于多项式b，你选择：\n";
	cout << "1. 手动创建\n";
	cout << "2. 随机创建(default)\n";
	cin >> b;
	if (b == 1) {
		cout << "请输入多项式b（最高次数为：" << MAXSIZE - 1 << "次）：\n";
		b_poly = createPoly(b_poly);
	}
	else {
		b_poly = createRandPoly();	//随机创建多项式
	}
	
	cout << "\n多项式b：\n";
	outputPoly(b_poly);

	cout << "\n相加的和为：\n";
	c_poly = addPoly(a_poly, b_poly);	//c_poly为相加的结果
	outputPoly(c_poly);

	cout << "\n相减（a - b）的和为：\n";
	c_poly = subPoly(a_poly, b_poly);	//c_poly为相减的结果
	outputPoly(c_poly);

	delete a_poly;
	delete b_poly;
	delete c_poly;
	return 0;
}
#endif
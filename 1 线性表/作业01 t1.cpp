#if 0
#include<iostream>
using namespace std;

int MAX_NUM = 2;    //动态数组的初始最大个数

struct student {
	int no;//学号
	string  name; //姓名
	char  sex; //性别 M 代表男，W代表女
	int   age;// 年龄
};

void printMenu() {
	cout << "======功能菜单======\n";
	cout << "  1---建立学生表\n";
	cout << "  2---添加一个学生\n";
	cout << "  3---插入一个学生\n";
	cout << "  4---删除一个学生\n";
	cout << "  5---显示全部学生表数据\n";
	cout << "  6---按学号查找学生数据\n";
	cout << "  0---退出\n";
	cout << "请选择功能：(1/2/3/4/5/6/0)\n";
}

//用于判断输入的性别是否符合要求
bool sexIsRight(char c) {
	return c == 'M' || c == 'W' || c == 'm' || c == 'w';
}

//根据学号找到某学生的位置，返回位置数。
int findStudentPos(student s[], const int sNUM, int no) {
	for (int i = 0; i < sNUM; i++) {
		if (s[i].no == no) {
			return i;
		}
	}
	return -1;  //找不到就返回-1
}

//5. 打印所有学生信息
void printStudentArray(const student s[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << "学号：" << s[i].no << endl;
		cout << "姓名：" << s[i].name << endl;
		cout << "性别：" << s[i].sex << endl;
		cout << "年龄：" << s[i].age << endl;
		cout << "----------------------------------------\n";
	}
}

//输入学生信息，假设输入的学号不会重复
bool enterStudentInfo(student& t) {
	cout << "请输入学号： " << endl;
	cin >> t.no;
	if (t.no == -9999) {
		return false;
	}
	cout << "请输入姓名： " << endl;
	cin >> t.name;
	cout << "请输入性别（M 代表男，W代表女）： " << endl;
	cin >> t.sex;
	while (!sexIsRight(t.sex)) {    //不对就一直输入
		cout << "请重新输入性别（M 代表男，W代表女）！： " << endl;
		cin >> t.sex;
	}
	cout << "请输入年龄： " << endl;
	cin >> t.age;
	cout << "\n";
	return true;
}

//扩展动态数组的大小
student* extendArray(student s[], const int n) {
	MAX_NUM = MAX_NUM * 1.5 + 2; //更新全局变量
	student* sArr = new student[MAX_NUM];
	for (int i = 0; i < n; i++) {
		sArr[i].no = s[i].no;
		sArr[i].name = s[i].name;
		sArr[i].sex = s[i].sex;
		sArr[i].age = s[i].age;
	}
	delete[] s;
	return sArr;
}

//1. 创建学生列表
student* createStudentArray(student s[], int& sNum) {
	enterStudentInfo(s[sNum]);  //建立一个学生
	sNum++; //学生数量加一
	while (enterStudentInfo(s[sNum])) {
		sNum++;
		if (sNum >= MAX_NUM) {
			s = extendArray(s, sNum);
		}
	}
	return s;
}

//2. 添加一个学生
student* appendStudent(student s[], int& sNUM) {
	if (sNUM >= MAX_NUM) {
		extendArray(s, sNUM);
	}
	if (enterStudentInfo(s[sNUM])) {  //输入学生信息
		sNUM++; //学生人数+1
	}
	return s;
}

//3. 在某位置插入一个学生
student* insertStudent(student s[], int& sNUM) {
	int pos;
	cout << "你想插在哪？\n";
	cin >> pos;
	//if (pos >= sNUM) {  //位置大于等于人数时，直接相当于append
	//    s = appendStudent(s, sNUM);
	//    return s;
	//}
	//else if (pos < 0) { //位置小于0
	//    cout << "该位置无效！\n";
	//    return s;
	//}
	student tem_s;  //临时储存学生信息，防止输入为-9999
	if (enterStudentInfo(tem_s)) {  //确实要插入
		sNUM++;
		if (sNUM >= MAX_NUM) {  //防止人数已经达到上限
			extendArray(s, sNUM);
		}
		for (int i = sNUM - 1; i > pos; i--) { //要么重载=，要么就这样赋值，不能直接s[i] = s[i - 1]
			s[i].no = s[i - 1].no;
			s[i].name = s[i - 1].name;
			s[i].age = s[i - 1].age;
			s[i].sex = s[i - 1].sex;
		}
		s[pos].no = tem_s.no;
		s[pos].name = tem_s.name;
		s[pos].age = tem_s.age;
		s[pos].sex = tem_s.sex;
	}
	return s;
}

//4. 删除学生
student* deleteStudent(student s[], int& sNUM) {
	int no, pos;
	cout << "请输入要删除的学生的学号：";
	cin >> no;
	pos = findStudentPos(s, sNUM, no);
	if (pos == -1)  //pos为-1的话，表明上面函数没有找到相应的学号
		cout << "查无此人\n";
	else {
		for (int i = pos; i < sNUM; i++) {
			s[i].no = s[i + 1].no;
			s[i].name = s[i + 1].name;
			s[i].age = s[i + 1].age;
			s[i].sex = s[i + 1].sex;
		}
		sNUM--; //人数-1
		cout << "删除成功！\n";
	}
	return s;
}

//6. 查找学生，显示他的信息
void findStudent(student s[], int& sNUM) {
	int no, pos;
	cout << "请输入要查找的学生的学号：";
	cin >> no;
	pos = findStudentPos(s, sNUM, no);
	if (pos == -1) {    ////pos为-1的话，表明上面函数没有找到相应的学号
		cout << "查无此人\n";
	}
	else {
		cout << "学号：" << s[pos].no << endl;
		cout << "姓名：" << s[pos].name << endl;
		cout << "性别：" << s[pos].sex << endl;
		cout << "年龄：" << s[pos].age << endl;
		cout << "----------------------------------------\n";
	}
}

int main() {
	student* studentArr = new student[MAX_NUM]; //使用动态分配内存
	int n;  //用于选择操作
	int studentNumber = 0;
	while (true) {
		printMenu();
		cin >> n;
		switch (n) {
		case 1:
			studentArr = createStudentArray(studentArr, studentNumber); //不给自己赋值就会导致溢出！
			system("pause");
			system("cls");
			break;  //break不能掉
		case 2:
			studentArr = appendStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 3:
			studentArr = insertStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 4:
			studentArr = deleteStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 5:
			printStudentArray(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 6:
			findStudent(studentArr, studentNumber);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "Bye~\n";
			delete[] studentArr;
			return 0;
		default:
			break;
		}
	}
	if (studentArr != NULL)  //防止未删除空间
		delete[] studentArr;
	return 0;
}
#endif
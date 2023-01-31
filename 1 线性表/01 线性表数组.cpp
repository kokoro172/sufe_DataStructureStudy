#if 0
#include <iostream>
using namespace std;
#define MAXSIZE 100
int table[MAXSIZE], n = 0;

void create_table()
{
	int x;
	cout << "please input data?";
	cin >> x;
	while (x != -9999)
	{
		table[n] = x; n++;
		cout << "please input data?";
		cin >> x;
	}
	return;
}
void out_table()
{
	int i;
	for (i = 0; i < n; i++)
		cout << table[i] << "   ";
	cout << endl;
	getchar(); getchar();
	return;
}
void append_data()
{
	cout << "please input append data?";
	cin >> table[n++];
	return;
}
void insert_data()
{
	int i, loc;
	cout << "please input insert loction?";
	cin >> loc;
	for (i = n - 1; i >= loc; i--)
		table[i + 1] = table[i];
	cout << "please input insert data?";
	cin >> table[loc];
	n++;
	return;
}

void deletedef_data() {
	int num, i = 0;
	cout << "Which num do you want to delete?\n";
	//cout << "where do you want to delete?\n";
	cin >> num;
	for (int tableNum : table) {
		if (tableNum == num) {
			for (int pos = i; pos < n; pos++) {
				table[pos] = table[pos + 1];
			}
			n--;
			return;
		}
		i++;
	}
	cout << "Can't find this number\n";
	system("pause");
	return;
	/*for (int i = loc; i < n; i++) {
		table[i] = table[i + 1];
	}
	n--;
	*/
}
int main()
{
	int choice;
	while (1)
	{
		system("cls");
		cout << "------MENU-------" << endl;
		cout << "  1----Create Table" << endl;
		cout << "  2----Out Table" << endl;
		cout << "  3----Append Data" << endl;
		cout << "  4----Insert Data" << endl;
		cout << "  5----Delete Data" << endl;
		cout << "  0----Quit" << endl;
		cout << " please choice function(1/2/3/4/5/0)";
		cin >> choice;
		if (choice == 1) create_table();
		if (choice == 2) out_table();
		if (choice == 3) append_data();
		if (choice == 4) insert_data();
		if (choice == 5) deletedef_data();
		if (choice == 0) break;
	}
	return 0;
}
#endif
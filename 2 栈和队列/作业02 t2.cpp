//#include<iostream>
//constexpr auto MAXSIZE = 10;;
//using namespace std;
//
//char  stack [MAXSIZE];
//int top = -1;
//int push(char  x){	//if push sucess  return 0,else return 1
//	if (top + 1 >= MAXSIZE) return 1;
//	top++;
//	stack[top] = x;
//	return 0;
//}
//int pop(char& y){	// if pop sucess  return 0,else return 1
//	if (top == -1) return 1;
//	y = stack[top];
//	top--;
//	return 0;
//}
//void disp_stack()
//{
//	for (int i = top; i >= 0; i--) {
//		cout << stack[i] << " ";
//	}
//	cout << "\n";
//}
//int  main()
//{
//	char ch = 'a';
//	if (pop(ch))
//		cout << "³öÕ»Ê§°Ü\n";
//	for (int i = 0; i < MAXSIZE; i++)
//		if (push(ch + i))
//			cout << "ÈëÕ»Ê§°Ü\n";
//	disp_stack();
//	if (push(ch + 6))
//		cout << "ÈëÕ»Ê§°Ü\n";
//	
//}

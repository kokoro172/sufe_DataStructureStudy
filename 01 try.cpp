//#include<iostream>
//using namespace std;
////
////char* delstr(char* strabc) {
////	int i = 0;
////
////	while (strabc[i] != '\0') {
////		if (strabc[i] >= 65 && strabc[i] <= 90 || strabc[i] >= 97 && strabc[i] <= 122) {
////			i++;
////			continue;
////		}
////		else {//不属于字母时
////			int tem = i;
////			while (strabc[tem] != '\0') {//把'\0'也搞过来
////				strabc[tem] = strabc[tem + 1];
////				tem++;
////			}
////		}
////	}
////	return strabc;
////}
////
////
////void merge(int a[], int b[],  int m, int n) {
////	m--; n--;
////	int i = 0, j = m + 1, k = 0;	//i、k开始，j中间
////	while (i != m + 1 && j != n + 1) {
////		if (a[i] > a[j]) {	//两个归到一起
////			b[k++] = a[j++];
////		}
////		else {
////			b[k++] = a[i++];
////		}
////	}
////	while (i != m + 1) b[k++] = a[i++];	//左边未到底
////	while (j != n + 1) b[k++] = a[j++];	//右半没到底
////	for (i = 0; i < n; i++)	//b储存排好的，最后把它放回a数组
////		a[i] = b[i];
////	for (i = 0; i <= n; i++) cout << a[i] << " ";
////}
//
//struct node { int data; node* next; };
//node* createNode(node *head,node *p) {
//	int n;
//	cin >> n;
//
//	if (head == NULL) {
//		head = new node;
//		head->data = 0;
//		head->next = NULL;
//		p = head;
//	}
//	if(n == -9999) {
//		return head;
//	}
//	else {
//		node* q = new node;
//		q->data = n;
//		p->next = q;
//		q->next = NULL;
//		head->data++;
//		p = q;
//
//	}
//	createNode(head, p);
//
//
//	/*node* head, * p, * q;
//	head = new node;
//	head->next = NULL;
//	head->data = 0;
//	p = head;
//
//	while (n != -9999) {
//		q = new node;
//		q->data = n;
//		p->next = q;
//		p = q;
//		head->data++;
//		cin >> n;
//	}*/
//}
//
//
////int printAndCount(node* head) {
////	node* tem = head->next;
////	int sum = 0;
////	while (tem != NULL) {
////		cout << tem->data << " -> ";
////		sum += tem->data;
////		tem = tem->next;
////	}
////	cout << endl;
////	return sum;
////}
//
////int strCompare(char* s1, char* s2) {
////	int i = 0;
////	while (s1[i] != '\0' && s2[i] != '\0') {
////		if (s1[i] == s2[i]) {
////			i++;
////			continue;
////		}
////		else if (s1[i] > s2[i])
////			return 1;
////		else
////			return -1;
////		i++;
////	}
////	if (s1[i] == '\0' && s2[i] == '\0') {
////		return 0;
////	}
////	else if (i == strlen(s1))
////		return 1;
////	else
////		return -1;
////}
//
//void merge(int a[], int b[], int begin, int mid, int end) {
//	int i = begin, j = mid + 1, k = begin;	//i、k开始，j中间
//	while (i != mid + 1 && j != end + 1) {
//		if (a[i] > a[j]) {	//两个归到一起
//			b[k++] = a[j++];
//		}
//		else {
//			b[k++] = a[i++];
//		}
//	}
//	while (i != mid + 1) b[k++] = a[i++];	//左边未到底
//	while (j != end + 1) b[k++] = a[j++];	//右半没到底
//	for (i = begin; i < end; i++)	//b储存排好的，最后把它放回a数组
//		a[i] = b[i];
//
//}
//
//void mergeSort(int a[], int b[], int begin, int end) {
//	int mid;
//	if (begin < end) {
//		mid = begin + (end - begin) / 2;
//		mergeSort(a, b, begin, mid);	//左
//		mergeSort(a, b, mid + 1, end);	//右
//		merge(a, b, begin, mid, end);
//	}
//}
//
//
//
//int main() {
//	//char a[] = "wang";
//	//char b[] = "wang";
//	//cout << strCompare(a,b);
//}
//
//
//
////node* head = NULL, *p = NULL;
////head = createNode(head, p);
//////p->next = NULL;
////cout << printAndCount(head) << endl;
////cout << "sad";
//
//
//
//
//
//
////int a[6] = { 1,2,99,98,97,96 };	//n=6
////int b[6];
////merge(a, b, 2, 6);
////for (int i : a) cout << i << " ";
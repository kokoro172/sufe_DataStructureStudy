#if 0
#include<iostream>
constexpr int MAXN = 11;
using namespace std;

void getNext(const string& str, int* next) {
	int j = 0;	//j指向后缀
	next[0] = j;
	for (int i = 1; i < str.size(); i++) {	//i从1开始， i指向前缀
		while (j > 0 && str[i] != str[j]) {	//前后缀不同，此处不可以是if，因为它是连续回退的
			j = next[j - 1];	//向前回退
		}
		if (str[i] == str[j])	//找到了相同的前后缀
			j++;
		next[i] = j;//将前缀的长度赋给next[i]
	}
}

//str是主串，p是模式串，next是回退用的数组
int kmpSearch(string str, string p) {
	int next[MAXN];
	getNext(p, next);//构建next数组

	int i = 0, j = 0;
	while (i < str.length()) {
		if (str[i] == p[j]) {	//匹配，指针后移
			i++; 
			j++;
		}
		else if (j > 0) {//不匹配，根据next回退
			j = next[j - 1];
		}
		else {	//第一个就不匹配
			i++;
		}
		if (j == p.size())	//匹配成功
			return i - j;
	}
	return -1;
}

int main() {
	string str1 = "wangkewangwawakekewei";
	string str2 = "wawakekew";
	int a[MAXN];
	getNext(str2, a);
	for (int i : a) cout << i << " ";
	cout << "\n";
	cout << kmpSearch(str1, str2);
}
#endif
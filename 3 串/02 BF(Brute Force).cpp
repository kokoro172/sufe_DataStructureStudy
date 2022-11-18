#if 0
#include<iostream>
using namespace std;

int bruteForce(string main, string sub) {
	int len_m = main.length();
	int len_s = sub.length();	//首先获取两个字符串的长度
	if (len_m < len_s) return -1;	//匹配串比主串大，直接返回

	for (int i = 0; i < len_m; i++) {	//遍历main字符串的每一个字符
		if (main[i] == sub[0]) {	//比较首字母，如果匹配就比较后面的
			int tem = i + 1;	//复制这个位置，
			int j = 1;	//j: 遍历sub的剩下字符
			for (; j < len_s && tem < len_m; j++, tem++) {	//任意一方到头就退出
				if (main[tem] != sub[j])	//如果有不匹配的，直接退出
					break;
			}
			if (j == len_s) return i;	//如果是j退出，返回该位置。注意此时的j是因为到了len_s才退出的
		}
	}
	return -1;	//找不到匹配的就返回-1
}


int main() {
	string str1, str2;
	str1 = "wangkewei";
	str2 = "wei";
	cout << bruteForce(str1, str2);
}
#endif
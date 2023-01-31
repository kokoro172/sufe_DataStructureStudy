#if 0
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void back_track(vector<int> ans, stack<int> stk, stack<int> input, vector<vector<int>>& result, int n) {
	if (ans.size() == n) {
		result.push_back(ans);
		return;
	}
	stack<int> stk_tmp = stk;
	vector<int> ans_tmp = ans;
	//输入直接出栈
	if (!stk.empty()) {
		ans.push_back(stk.top());
		stk.pop();
		back_track(ans, stk, input, result, n);
	}
	//输入直接入栈
	if (!input.empty()) {
		stk_tmp.push(input.top());
		input.pop();
		back_track(ans_tmp, stk_tmp, input, result, n);
	}
}
int main() {
	stack<int> stk;
	vector<int> ans;
	stack<int> input;
	vector<vector<int>> result;
	int num = 5; //入栈元素数量
	for (int i = num; i > 0; --i) {
		input.push(i);
	}
	vector<vector<int>> store;
	back_track(ans, stk, input, result, num);
	for (vector<int>& vec : result) {
		for (int& i : vec) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "count: " << result.size();
}
#endif
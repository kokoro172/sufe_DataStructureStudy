#if 0
#include<iostream>
#include<stack>
constexpr int MAX = 50;	//整个迷宫最大边长
constexpr int DIR = 4;	//方向数
using namespace std;

struct Move {
	int a, b;	//a--行（上下走），b--列（左右走）
};

struct point {	//表示迷宫的点，包括坐标和下一步走的方向
	int x, y, d;//x:行，y:列，d:方向（0~DIR - 1)
	point(int a, int b, int c) {	//构造函数，方便输入
		x = a; y = b; d = c;
	}
	void makePoint(int a, int b, int c) {	//赋值用的函数，方便输入
		x = a; y = b; d = c;
	}
};

class Maze {
public:
	char board[MAX][MAX];	//储存迷宫的样子，由于需要把路变成*，所以类型是char
	int mark[MAX][MAX];	//被走过就是1，没有就是0，其实bool也行；由于不可能出现“一条不通的路和一条通的路都经过这一点”，所以变成1就是1了
	int m = 0, n = 0;	//迷宫的大小，m:行,n:列，人为改变
	Move mv[DIR];	//走的方向——上下左右，DIR是方向的数量，可能不止有上下左右
	stack<point> s;	//用于寻找路的栈，最后要么储存这条路，要么为空表示找不到路。

	Maze(int a, int b);	//构造函数，初始化边界和内部大小，还有移动方向
	void refreshMaze();	//这个函数作用是找到到达终点的路后，把这条路换成*。
	void createMaze();	//创建自定义的迷宫
	void outputMaze();	//输出迷宫（包括边界）
	int getPath(int beg_a, int beg_b, int end_a, int end_b);	//生成路径，前两个参数是起点，后两个是终点。给程序增加更大的灵活性
};


//构造函数，初始化边界和内部大小
Maze::Maze(int a, int b) {
	m = a; n = b;
	for (int i = 0; i < m + 2; i++) {
		for (int j = 0; j < n + 2; j++) {
			board[i][j] = '1';	//把所有的包括边界的格子初始化为1
			mark[i][j] = 0;	//所有的格子都标记为未走过
		}	
	}

	mv[0].a = 0; mv[0].b = -1;	//往左
	mv[1].a = 1; mv[1].b = 0;	//往下
	mv[2].a = -1; mv[2].b = 0;	//往上
	mv[3].a = 0; mv[3].b = 1;	//往右
}

//把路线变成*
void Maze::refreshMaze() {
	while (!s.empty()) {
		int a = s.top().x; 
		int b = s.top().y;
		board[a][b] = '*';
		s.pop();
	}
}

//输入迷宫内部
void Maze::createMaze(){
	cout << "input maze:\n";
	for (int x = 1; x <= m; x++)
		for (int y = 1; y <= n; y++)
			cin >> board[x][y];
}

//输出迷宫
void Maze::outputMaze() {
	cout << "output maze:\n";
	for (int i = 0; i <= m + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";	
	}
	cout << "\n";
}

//得到路径,beg_a:起点行数（纵坐标），beg_b:起点列数（横坐标）
int Maze::getPath(int beg_a, int beg_b, int end_a, int end_b) {
	beg_a = 1; beg_b = n;	//起点：右上，终点：左下
	end_a = m; end_b = 1;	//由于题目的起点和终点都已经确定，所以就在这里写死了，无论传进来什么都会变的

	if (board[1][n] == '1' || board[m][1] == '1') return 1;	//如果起点终点有到不了的，直接返回
	point tem_p(beg_a, beg_b, -1);	//初始化
	s.push(tem_p);		//先将起点压入栈
	mark[beg_a][beg_b] = 1;	//起点走过了

	int nowRow, nowCol;	//现在的行和列
	int nextRow, nextCol; //下一个方向的行和列
	int dir;	//方向数

	tem_p.makePoint(0, 0, -1); s.push(tem_p);	//先加一个点进去，交给下面的while循环判断（为了凑成while）

	//此处使用DFS
	while (1) { //栈不空
		s.pop();	//如果这个点后面的路行不通，就退回去一格，看看有没有其他方向
		if (s.empty()) return 1;//如果栈空了，直接结束
		nowRow = s.top().x;
		nowCol = s.top().y;	//更新如今的坐标为：回退一格后的坐标
		dir = s.top().d;	//接着上次的方向继续遍历下去

		while (dir < DIR - 1) {	//遍历每一个方向，由于dir是从-1开始（下面是++dir，先加再赋值的），所以DIR要-1
			nextRow = nowRow + mv[++dir].a;
			nextCol = nowCol + mv[dir].b;	//下一步走到的坐标
			if (nextRow == end_a && nextCol == end_b) {	//找到了终点
				if (s.top().x == 0 && s.top().y == 0) s.pop();	//保险起见，免得多塞了一个点进去
				tem_p.makePoint(nowRow, nowCol, dir); s.push(tem_p);
				tem_p.makePoint(nextRow, nextCol, dir); s.push(tem_p);	//把终点也推进去
				refreshMaze();	//把路变成*
				outputMaze();	//输出最后的迷宫
				return 0;	//记得直接结束
			}
			if (board[nextRow][nextCol] == '0' && mark[nextRow][nextCol] == 0) {	//这个位置可以走，而且没走过
				mark[nextRow][nextCol] = 1;	//这个点要走了

				s.top().x = nowRow;
				s.top().y = nowCol;	//坐标的更新有一种“滞后性”，这样相当于提前找下下个点
				s.top().d = dir;	//更新当前点位的方向
				
				tem_p.makePoint(0, 0, -1);	s.push(tem_p);//这就是滞后性
				nowRow = nextRow; nowCol = nextCol;	//把当前坐标更新为下一个坐标
				dir = -1;	//把方向也更新一下
			}
		}
	}
	return 1;
}

int main() {
	int m, n;
	cout << "input m n:\n";
	cin >> m >> n;

	Maze mz(m, n);
	mz.createMaze();
	mz.outputMaze();
	if (mz.getPath(1, n, m, 1)) {	//因为返回值为1的话，就表示不能生成（人为定义的）
		cout << "Error! No path!\n";
	}
	return 0;
}

#endif
#if 0
#include <iostream>
using namespace  std;
#define MAX 50
struct stack
{
	int x, y, d;    //d的作用？
};

struct Move //往哪个方向走
{
	int a, b;
};
int maze[MAX][MAX];
int mark[MAX][MAX];
Move mv[8];
stack s[MAX * MAX];
int top;

void setmove()  //设置好方向
{
	mv[0].a = -1;    mv[0].b = 0;
	mv[1].a = -1;    mv[1].b = 1;
	mv[2].a = 0;    mv[2].b = 1;
	mv[3].a = 1;    mv[3].b = 1;
	mv[4].a = 1;    mv[4].b = 0;
	mv[5].a = 1;    mv[5].b = -1;
	mv[6].a = 0;    mv[6].b = -1;
	mv[7].a = -1;    mv[7].b = -1;
}

//输入自定义的迷宫
void inputmaze(int m, int n)
{
	int i, j;
	cout << "Input maze : \n";
	for (i = 0; i <= m + 1; i++)
		for (j = 0; j <= n + 1; j++)
			maze[i][j] = 1; //初始化，全部为1
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
			cin >> maze[i][j];  //边框保留为1，中间可以填
	}
}

//输出迷宫，包括边界和自定义的
void outputmaze(int m, int n)
{
	int  i, j;
	cout << "Output maze: \n";
	for (i = 0; i <= m + 1; i++)
	{
		for (j = 0; j <= n + 1; j++)
			cout << maze[i][j];
		cout << endl;
	}
}

//难道是记录轨迹用的？还是有没有被访问？
void setmark(int m, int n)
{
	int i, j;
	for (i = 0; i <= m + 1; i++)
		for (j = 0; j <= n + 1; j++)
			mark[i][j] = 0;
}

int getmazepath(int m, int n)
{
	int  i, j, k, g, h, t;
	if (maze[1][1] != 0 || maze[m][n] != 0)
		return (1);
	s[0].x = 1;
	s[0].y = 1;
	s[0].d = 1; //起点1,1
	top = 1;
	mark[1][1] = 1;
	while (top > 0)
	{
		i = s[--top].x; //如果找不到就top--，往回看看
		j = s[top].y;
		k = s[top].d;   //继承上一次前进的方向，接着找其他方向，因为方向数都是从0~7找
		while (k < 7)   //如果能找就一直找下去
		{
			g = i + mv[++k].a;
			h = j + mv[k].b;//i,j代表现在的位置，g,h代表下一步的位置？

			//找到终点
			if (g == m && h == n)
			{
				cout << "path in maze:\n";
				for (t = 0; t < top; t++)
					cout << s[t].x << "  " << s[t].y << endl;
				cout << i << "  " << j << endl;
				cout << m << "  " << n << endl;
				return(0);
			}
			//下一个可以走
			if (maze[g][h] == 0 && mark[g][h] == 0)
			{
				mark[g][h] = 1;
				s[top].x = i;
				s[top].y = j;
				s[top++].d = k;
				i = g;
				j = h;
				k = -1; //刷新k，到下一个点时从第一个方向开始找
			}
		}  /* while k  */
	} /*while  top  */
	return (1);
}

int main() {
	int m, n;
	cout << "input m n\n";
	cin >> m >> n;
	setmove();
	inputmaze(m, n);
	outputmaze(m, n);
	setmark(m, n);
	if (getmazepath(m, n)) cout << "Error! No path!\n";
	return 1;
}
#endif
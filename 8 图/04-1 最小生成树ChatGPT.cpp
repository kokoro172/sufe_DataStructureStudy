#if 0
#include <iostream>
using namespace std;

//! 定义最大值
#define MAXN 50

//! 定义结构体
struct L_node {
	int ver; //! 顶点
	L_node* link; //! 指向下一个结点的指针
};

//! 定义结构体数组
L_node* head[MAXN];

//! 定义拓展结点
struct E_node {
	int ver1, ver2; //! 顶点1和顶点2
};

//! 定义拓展结点数组
E_node e[MAXN];

//! 定义变量
int n, m, u;

// 函数用于创建邻接表
// 输入：链表头数组、结点个数、边数组、边数
/**
 * .
 *
 * \param head 链表头数组
 * \param n 结点个数
 * \param e 边数组
 * \param m 边数
 */
void create_adj_list(L_node* head[], int n, E_node e[], int m)
{
	// 定义临时变量
	int i, u, v;
	L_node* p;

	// 初始化链表头数组
	for (i = 1; i <= n; i++)
		head[i] = NULL;

	// 遍历边数组
	for (i = 0; i < m; i++)
	{
		// 获取边的两个结点
		u = e[i].ver1;
		v = e[i].ver2;

		// 创建新结点
		p = new L_node;
		p->ver = v;  // 设置结点编号

		// 将新结点加入u结点的链表
		p->link = head[u];
		head[u] = p;

		// 创建新结点
		p = new L_node;
		p->ver = u;  //
	}
}

//! 定义DFS最小生成树算法
void dfs(int u)
{
	//! 定义指向结点的指针
	L_node* t;
	//! 访问顶点
	visit[u] = 1;
	//! 指向下一个结点
	t = head[u];
	//! 处理当前结点的每个拓展结点
	while (t != NULL)
	{
		//! 取出当前拓展结点的顶点
		int w = t->ver;
		//! 如果没有访问过
		if (visit[w] == 0)
		{
			//! 输出最小生成树的边
			cout << u << "----" << w << endl;
			//! 处理当前拓展结点
			dfs(w);
		}
		//! 指向下一个拓展结点
		t = t->link;
	}
}

int main()
{
	//! 输入顶点和拓展
	cin >> n >> m;

	//! 建立邻接表
	create_adj_list(head, n, e, m);

	//! 从顶点1开始处理
	dfs(1);

	return 0;
}
#endif
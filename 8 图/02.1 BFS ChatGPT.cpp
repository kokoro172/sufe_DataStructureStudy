#if 0
/**

@file bfs.cpp
@brief 广度优先搜索算法
@author 路远
*/
#include <iostream>

using namespace std;

//! 定义最大值
#define MAXN 50

//! 定义结构体
struct L_node {
int ver; //! 顶点
L_node *link; //! 指向下一个结点的指针
};

//! 定义结构体数组
L_node *head[MAXN];

//! 定义拓展结点
struct E_node {
int ver1, ver2; //! 顶点1和顶点2
};

//! 定义拓展结点数组
E_node e[MAXN];

//! 定义变量
int n, m, u;

//! 定义队列类型
struct qtype {
int qa, qe; //! 队列开始和队列结束的位置
int item[MAXN]; //! 队列中的项
};

//! 定义广度优先搜索算法
void bfs(int u)
{
//! 定义队列
qtype queue;
//! 定义顶点变量
int v, w;
//! 定义指向结点的指针
L_node *t;

Copy code
//! 输出顶点
cout << u;
//! 访问顶点
visit[u] = 1;
//! 初始化队列
queue.qa = 0;
queue.qe = 0;
//! 第一个项放入队列
queue.item[0] = u;
//! 队列中还有项未处理
while (queue.qa <= queue.qe)
{
    //! 取出队列中的一个项
    v = queue.item[queue.qa++];
    //! 指向下一个结点
    t = head[v];
    //! 处理当前结点的每个拓展结点
    while (t != NULL)
        
}

#endif
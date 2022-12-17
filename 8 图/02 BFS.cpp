#if 0
#include<iostream>
#define  MAXN  50
#define MAXM 100
using namespace std;

/**
 * @file   main.cpp
 * @author
 * @date
 * @brief
 */

#include<iostream>
using namespace std;

// 定义最大结点数和边数
#define  MAXN  50
#define MAXM 100

// 定义链表结点类型
struct  L_node {
    int ver;  // 结点的编号
    L_node* link;  // 指向下一个结点的指针
};

// 定义图中边的结构体
struct  E_node {
    int ver1, ver2;  // 边的两个结点
};

// 定义链表头数组
L_node* head[MAXN];

// 定义边数组
E_node  e[MAXM];

//定义访问过的数组
int visit[MAXN];

// 定义结点个数、边数、起始结点编号
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

// 函数用于宽度优先搜索
// 输入：起始结点编号u

void bfs(int u)
{
    // 定义队列
    struct  qtype {
        int qa;  // 队列的队头指针
        int qe;  // 队列的队尾指针
        int item[MAXN];  // 队列数组
    };

    // 定义临时变量
    int v, w;
    L_node* t;

    // 定义队列
    qtype  queue;

    // 输出起始结点的编号
    cout << u;

    // 标记结点u已被访问
    visit[u] = 1;

    // 初始化队列
    queue.qa = 0;
    queue.qe = 0;
    queue.item[0] = u;

    // 循环遍历队列
    while (queue.qa <= queue.qe)
    {
        // 获取队头结点的编号
        v = queue.item[queue.qa++];

        // 指针指向结点v的链表头结点
        t = head[v];

        // 循环遍历结点v的链表
        while (t != NULL)
        {
            // 获取结点的编号
            w = t->ver;

            // 如果结点w没有被访问，则将其加入队列
            if (visit[w] == 0)
            {
                // 输出结点编号
                cout << w;

                // 标记结点w已被访问
                visit[w] = 1;

                // 将结点w加入队列
                queue.item[++queue.qe] = w;
            }

            // 指针指向下一个结点
            t = t->link;
        }
    }
}

int main() {
    create_adj_list(head, 3, e, 2);
}

#endif
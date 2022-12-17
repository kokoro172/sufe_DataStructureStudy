#if 0
#include<iostream>
using namespace std;
#define  MAXN  50
#define MAXM 100
struct  L_node { int ver;  L_node* link; };
struct  E_node { int ver1, ver2; };
L_node* head[MAXN];
E_node  e[MAXM];
int n, m, u;;
void create_adj_list(L_node head[], int n, E_node e[], int m)
{
    int i, u, v;
    L_node* p;
    for (i = 1; i <= n; i++)
        head[i] = NULL;
    for (i = 0; i < m; i++)
    {
        u = e[i].ver1; v = e[i].ver2;
        p = new L_node;
        p->ver = v;
        p->link = head[u];
        head[u] = p;
        p = new L_node;
        p->ver = u;
        p->link = head[v];
        head[v] = p;
    }
}
void init(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        visit[i] = 0;
}
  
  void  dfs(int u)
  {
      L_node* t;
      visit[u] = 1;
      cout << u;
      t = head[ui];
      while (t != NULL)
      {
          if (visit[t->ver] == 0)
              dfs(t->ver);
          t = t->link;
      }

  }



#endif
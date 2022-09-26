//#include <iostream>
//using namespace  std;
//#define MAX 50
//struct stack
//{
//    //x行y列
//    int x, y, d;    //d的作用？是direction，表示往几号方向走的，便于回退后接着遍历方向
//};
//
//struct Move //往哪个方向走
//{
//    int a, b;   //a行，b列
//};
//int maze[MAX][MAX]; //储存迷宫
//int mark[MAX][MAX]; //大概是储存走过的路，走过就记为1
//Move mv[4]; //走的4个方向
//stack s[MAX * MAX]; //栈，储存路径
//int top;    //栈顶位置
//
//void setmove()  //设置好方向，只能走4个
//{
//    mv[0].a = -1;    mv[0].b = 0;   //上
//    mv[1].a = 0;    mv[1].b = -1;   //左
//    mv[2].a = 0;    mv[2].b = 1;    //右
//    mv[3].a = 1;    mv[3].b = 0;    //下
//
//}
//
////输入自定义的迷宫
//void inputmaze(int m, int n)
//{
//    int i, j;
//    cout << "Input maze : \n";
//    for (i = 0; i <= m + 1; i++)
//        for (j = 0; j <= n + 1; j++)
//            maze[i][j] = 1; //初始化，全部为1
//    for (i = 1; i <= m; i++)
//    {
//        for (j = 1; j <= n; j++)
//            cin >> maze[i][j];  //边界保留为1，中间可以填
//    }
//}
//
////输出迷宫，包括边界和自定义的
//void outputmaze(int m, int n)
//{
//    int  i, j;
//    cout << "Output maze: \n";
//    for (i = 0; i <= m + 1; i++)
//    {
//        for (j = 0; j <= n + 1; j++)    
//            cout << maze[i][j];
//        cout << endl;
//    }
//}
//
////难道是记录轨迹用的？还是有没有被访问？
//void setmark(int m, int n)
//{
//    int i, j;
//    for (i = 0; i <= m + 1; i++)
//        for (j = 0; j <= n + 1; j++)
//            mark[i][j] = 0;
//}
//
//int getmazepath(int m, int n)
//{
//    int  i, j, k, g, h, t;  
//    if (maze[1][n] != 0 || maze[m][1] != 0) //起点终点不能到达，直接结束。此处的mn包含了边界，故不需要-1
//        return (1);
//    s[0].x = 1;
//    s[0].y = n; //设置起点入栈
//    s[0].d = -1;
//    top = 1;    //栈顶
//    mark[1][n] = 1;
//    while (top > 0)	//如果下一个点有能走的路，就走过去
//    {
//        i = s[--top].x;
//        j = s[top].y;
//        k = s[top].d;
//        while (k < 3)
//        {
//            g = i + mv[++k].a;
//            h = j + mv[k].b;
//            if (g == m && h == 1)   //到达终点后，输出路径
//            {
//                cout << "path in maze:\n";
//                for (t = 0; t < top; t++)
//                    cout << s[t].x << "  " << s[t].y << endl;
//                cout << i << "  " << j << endl;	//现在倒的位置
//                cout << m << "  " << 1 << endl;	//由于能进到这里，表示下一个就是终点了
//                return(0);
//            }
//            if (maze[g][h] == 0 && mark[g][h] == 0) //这个地方可以走，而且没走过
//            {
//                mark[g][h] = 1;
//                s[top].x = i;
//                s[top].y = j;	
//                s[top++].d = k;	
//                i = g;
//                j = h;
//                k = -1;
//            }
//        }  /* while k  */
//    } /*while  top  */
//    return (1);
//}
//
//int main(){
//    int m, n;
//    cout << "input m n\n";
//    cin >> m >> n;
//    setmove();
//    inputmaze(m, n);
//    outputmaze(m, n);
//    setmark(m, n);
//    if (getmazepath(m, n)) cout << "Error! No path!\n";
//    return 1;
//}

//#include  <iostream>
//using namespace std;
//#define MAXN 100
//struct  TERM {
//    int c;
//    int e;
//};
//
//int append(int c, int e, int free9, TERM poly[])
//{
//    if (free9 >= MAXN)  return(1);  /*空间已满，出错*/
//    poly[free9].c = c;
//    poly[free9++].e = e;
//    return(0);      /*已加入一项，正常返回*/
//}
//int poly_add(int &ah, int &at, int &bh, int &bt, int &chn, int &ct, int &free9, TERM poly[])
//{
//    int p, q, pe, qe, c;
//    char ch;
//    p = ah;
//    q = bh;
//    chn = free9;
//    while (p <= at && q <= bt)
//    {
//        pe = poly[p].e;
//        qe = poly[q].e;
//        if (pe == qe) ch = '=';
//        else if (pe < qe) ch = '<';
//        else ch = '>';
//        switch (ch)
//        {
//        case '=':
//            c = poly[p].c + poly[q].c;
//            if (c)  if (append(c, pe, free9, poly))  return(1);
//            p++;
//            q++;
//            break;
//        case '<':
//            if (append(poly[q].c, qe, free9, poly))
//                return(1);
//            q++;
//            break;
//        case '>':
//            if (append(poly[p].c, pe, free9, poly))  return(1);
//            p++;
//            break;
//        }
//    }
//    while (p <= at)
//    {
//        if (append(poly[p].c, poly[p].e, free9, poly))
//            return (1);
//        p++;
//    }
//    while (q <= bt)
//    {
//        if (append(poly[q].c, poly[q].e, free9, poly))
//            return (1);
//        q++;
//    }
//    ct = free9 - 1;
//    return (0);
//}
//int main()
//{
//    TERM  poly[MAXN] = { {5,4},{3,2},{-7,1},{3,0},{5,4},{4,3},{-3,2},{1,1},{5,0} };
//    int ah = 0, at = 3, bh = 4, bt = 8, ch, ct, free9 = 9;
//    int i;
//    if (poly_add(ah, at, bh, bt, ch, ct, free9, poly)) { cout << "Error!" << endl; return 0; }
//    ch = bt + 1;
//    for (i = ch; i <= ct; i++)
//        cout << "+" << poly[i].c << "X(" << poly[i].e << ")";
//    cout << endl;
//    return 0;
//}

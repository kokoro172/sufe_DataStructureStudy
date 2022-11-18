#if 0
#include<iostream>
constexpr int MAXN = 10;
using namespace std;

void mat_fast_transpose(int a[][3], int b[][3])
{
	int m, n, t, i, j;
	int x[MAXN], y[MAXN];
	m = a[0][0];
	n = a[0][1];
	t = a[0][2];
	b[0][0] = n;
	b[0][1] = m;
	b[0][2] = t;
	if (t > 0)
	{
		for (i = 0; i < n; i++)
			x[i] = 0;
		for (i = 1; i <= t; i++)
			x[a[i][1]] += 1;
		y[0] = 1;
		for (i = 1; i < n; i++)
			y[i] = y[i - 1] + x[i - 1];
		for (i = 1; i <= t; i ++)
		{
			j = y[a[i][1]];
			b[j][0] = a[i][1];
			b[j][1] = a[i][0];
			b[j][2] = a[i][2];
			y[a[i][1]] = j + 1;
		}
	}
}
int main() {

}

#endif
#if 0
#include<iostream>
#include<string>
#define MAXN 100
using namespace std;

//char s[MAXN], sl[MAXN], s2[MAXN];
int strlen(char s[])
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
	return (i);
}

bool strcat(char s1[], char  s2[])
{
	int i, j, k = 0;
	if ((i = strlen(s1)) + (j = strlen(s2)) >= MAXN)
		return (false);
	//for (k = strlen(s1) - 1; k >= 0; k--)	//从最后一位开始
	//	if (s1[k] != ' ')
	//		break;
	for (; k <= j; k++)
		s1[i + k] = s2[k];
	return (true);
}

bool strsub(char sl[], int  i, int  j, char  s2[])
{
	int m, k;
	if (i < 0 || i >= (m = strlen(sl)))
		return (false);
	if (j<0 || i + j>m)
		return (false);
	for (k = 0; k < j; k++)
		s2[k] = sl[i + k];
	s2[k] = '\0';
	return (true);
}

bool strins(char sl[], int i, char  s2[]) {
	int m, n, k;
	if (i<0 || i>(m = strlen(sl)) || m + (n = strlen(s2)) > MAXN)
		return(false);
	for (k = m; k >= i; k--)
		sl[k + n] = sl[k];
	for (k = 0; k < n; k++)
		sl[i + k] = s2[k];
	return (true);
}

bool strdel(char s[], int  i, int  j)
{
	int m, k;
	if (i < 0 || i >= (m = strlen(s)))
		return (false);
	if (i + j >= m)
		s[i] = '\0';
	else
		for (k = 0; k <= m - i - j; k++)
			s[i + k] = s[i + j + k];
	return (true);
}

bool strequ(char s1[], char s2[])
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return(true);
	else
		return(false);
}

char str1[MAXN] = "wqwe  ", str2[MAXN] = "999";

int main() {
	cout << "str1:\n";
	cin.getline(str1, MAXN);
	cout << "str2:\n";
	cin.getline(str2, MAXN);
}
#endif
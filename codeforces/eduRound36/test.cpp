#include <bits/stdc++.h>
using namespace std;
char a[100], b[100];
int A[1001], B[1001], Vis[1001];
int Tmp[1001];
int N, M;
inline int cmp(int a, int b)
{
	return a > b;
}
inline int Check(int x, int y)//��xλ��A[y]�����
{
	if (A[y] > B[x]) return 0;
	if (A[y] < B[x]) return 2;
	int cnt = 0;
	memset(Tmp, 0, sizeof(Tmp));
	for (int i = 1; i <= N; ++i)
		if (i != y && !Vis[i]) Tmp[++cnt] = A[i];
	sort(Tmp + 1, Tmp + cnt + 1);
//	for (int i = 1; i <= cnt; ++i) cout<<Tmp[i];
//	cout<<endl;
	int fl = 0, flag = 0, CNT = 0;
	for (int i = x + 1, j = 1; i <= N, j <= cnt; ++i, ++j)
	{
		flag = 1;
		if (Tmp[j] < B[i]){fl = 1;break;}
		else if (Tmp[j] == B[i]) CNT++;
		else return 0;
	}
//	cout<<x<<" "<<y<<" "<<fl<<" "<<flag<<endl;
	if (CNT == cnt) return 1;
	if (!fl && flag) return 0;
	if (A[y] == B[x]) return 1;
}
inline void dfs(int x)
{
	for (int i = 1; i <= N; ++i)
	{
		if (!Vis[i])
		{
			int pd = Check(x, i);
//			cout<<x<<" "<<i<<" "<<pd<<endl;
			if (pd == 2)
			{
				cout<<A[i];
				Vis[i] = 1;
				for (int j = 1; j <= N; ++j)
					if (!Vis[j]) cout<<A[j];
				exit(0);
			}
			else if (pd == 1)
			{
				Vis[i] = 1;
				cout<<A[i];
				dfs(x + 1);
				exit(0);
			}
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	scanf("%s%s", a, b);
	N = strlen(a), M = strlen(b);
	for (int i = 0; i < N; ++i)
		A[i + 1] = a[i] - '0';
	for (int i = 0; i < strlen(b); ++i)
		B[i + 1] = b[i] - '0';
	sort(A + 1, A + N + 1, cmp);
	if (M > N)
	{
		for (int i = 1; i <= N; ++i) cout<<A[i];
		cout<<endl;
		return 0;
	}
	dfs(1);
	return 0;
}
//https://codeforces.com/contest/1200/problem/D

// CREDIT : https://codeforces.com/profile/oliviahye
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
char a[2003][2003];
int dy[2003][2003];
int y[2003][2003];
int yes = 0;
void upd(int x1, int x2, int y1, int y2)
{
	dy[x1][y1]++;
	dy[x2][y2]++;
	dy[x1][y2]--;
	dy[x2][y1]--;
}
int main()
{
	freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		int mi = 0, ma = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 'B')
			{
				ma = j;
				if (!mi)
					mi = j;
			}
		}
		if (mi == 0)
			yes++;
		else if (ma - mi + 1 <= k)
			upd(max(0, i - k), i, max(0, ma - k), mi);
	}
	for (int j = 1; j <= n; j++)
	{
		int mi = 0, ma = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i][j] == 'B')
			{
				ma = i;
				if (!mi)
					mi = i;
			}
		}
		if (mi == 0)
			yes++;
		else if (ma - mi + 1 <= k)
			upd(max(0, ma - k), mi, max(0, j - k), j);
	}
	int ans = 0;
	for (int i = n; i >= 1; i--)
	{
		for (int j = n; j >= 1; j--)
		{
			y[i][j] = -y[i + 1][j + 1] + y[i][j + 1] + y[i + 1][j] + dy[i][j];
			ans = max(ans, yes + y[i][j]);
		}
	}
	cout << ans << endl;
}

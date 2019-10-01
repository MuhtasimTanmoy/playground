//https://practise/problem/B
// https://codeforces.com/contest/965/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REPI(i, a, b) for (int i = (a); (i <= (b)); ++i)
#define x first
#define y second
using namespace std;

///REF PII

typedef pair<int, int> pii;

const int INF = 2e9;
const ll INF64 = 1e18;
const int M = 2 * 1000 * 1000;
const int N = 101;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.14159265359;

template <typename T>
T gcd(T x, T y)
{
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x % y);
}

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

char a[110][110];
ll cnt[110][110];
int solve()
{
	ll i, j, k, n, p, m, fl, ans = -1, mx1, mx2;
	string s;
	cin >> n >> p;
	for (i = 1; i <= n; i++)
	{
		cin >> s;
		for (j = 1; j <= n; j++)
			a[i][j] = s[j - 1];
	}
	for (i = 1; i <= n; i++)
	{
		for (j = p; j <= n; j++)
		{
			fl = 1;
			for (k = j - p + 1; k <= j; k++)
				if (a[i][k] == '#')
					fl = 0;
			if (fl)
				for (k = j - p + 1; k <= j; k++)
					cnt[i][k]++;
		}
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << cnt[i][j];
		}
		cout << endl;
	}
	for (j = 1; j <= n; j++)
	{
		for (i = p; i <= n; i++)
		{
			fl = 1;
			for (k = i - p + 1; k <= i; k++)
				if (a[k][j] == '#')
					fl = 0;
			if (fl)
				for (k = i - p + 1; k <= i; k++)
					cnt[k][j]++;
		}
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (cnt[i][j] > ans)
				ans = cnt[i][j], mx1 = i, mx2 = j;
	cout << mx1 << ' ' << mx2 << endl;
	return 0;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	//cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

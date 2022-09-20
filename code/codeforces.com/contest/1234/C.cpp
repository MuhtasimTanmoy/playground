//https://codeforces.com/contest/1234/problem/C
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
const int N = 300 * 1000 + 100;
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

void solve()
{
	int n;
	cin >> n;

	int grid[3][n + 1];

	char ch;

	for (int i = 1; i <= n; i++)
	{
		cin >> ch;
		grid[1][i] = ch - '0';
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> ch;
		grid[2][i] = ch - '0';
	}

	set<int> a = {1, 2};
	set<int> b = {3, 4, 5, 6};

	if (n == 1)
	{
		if (b.count(grid[1][1]) && b.count(grid[2][1]))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		return;
	}

	int distance = 1;
	int level = 1;

	bool fromSetA = true;
	bool levelChange = false;

	while (distance != n + 1)
	{
		if (a.count(grid[level][distance]))
		{
			if (!fromSetA && levelChange)
			{
				break;
			}
			distance++;
			fromSetA = true;
			levelChange = false;
		}
		else
		{
			if (!levelChange)
			{
				if (level == 2)
				{
					level--;
				}
				else
				{
					level++;
				}
				fromSetA = false;
				levelChange = true;
			}
			else
			{
				distance++;
				levelChange = false;
			}
		}
	}

	if (distance == n + 1 && level==2)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
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
	cin >> no_of_test_cases;
	// no_of_test_cases=1;
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

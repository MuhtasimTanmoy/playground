//https://codeforces.com/contest/1200/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define ull unsigned long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

void solve()
{
	ull n, m, q;
	cin >> n >> m >> q;
	bool blocked = false;

	if (n == m)
	{
		blocked = true;
	}

	pair<int, int> from;
	pair<int, int> to;

	bool fromRight;
	bool toRight;

	REP(i, q)
	{
		cin >> from.first >> from.second;
		cin >> to.first >> to.second;

		if (n == 1 || m == 1)
		{
			cout << "YES" << endl;
			continue;
		}

		if (!blocked)
		{
			fromRight = (from.second > (from.first == 1 ? n / 2 : m / 2)) ? false : true;

			toRight = (to.second > (to.first == 1 ? n / 2 : m / 2)) ? false : true;

			if (fromRight == toRight)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}

		else
		{
			cout << (from.second == to.second ? "YES" : "NO") << endl;
		}
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
	//cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	// __gcd()

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

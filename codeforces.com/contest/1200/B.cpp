//https://codeforces.com/contest/1200/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int columns[1000001];

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	REP(i, n)
	{
		cin >> columns[i];
	}

	int completed = 0;

	int target = 0;
	int needed = 0;

	bool done = true;

	while (completed != n - 1)
	{
		target = max(columns[completed + 1] - k, 0);

		needed = target - columns[completed];

		if (needed < 0)
		{
			m -= needed;
		}
		else if (needed > 0)
		{
			if (m >= needed)
			{
				m -= needed;
			}
			else
			{
				cout << "NO" << endl;
				return;
			}
		}
		completed++;
	}

	cout << "YES" << endl;
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

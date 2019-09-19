// https://codeforces.com/contest/1221/problem/A
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

int li[12];
void solve()
{
	int n;
	cin >> n;

	int holder;
	int sum = 0;

	int base = 0;

	REP(i, 12)
	{
		li[i] = 0;
	}

	REP(i, n)
	{
		cin >> holder;
		int base = 0;
		while (holder % 2 == 0) {
			holder /= 2;
			base++;
		}
		if (base < 12)
		{
			li[base] += 1;
		}
	}

	if (li[11])
	{
		cout << "YES" << endl;
		return;
	}
	else
	{
		REP(i, 11)
		{
			li[i + 1] += li[i] / 2;
			li[i] = li[i] % 2;
		}

		if (li[11])
		{
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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

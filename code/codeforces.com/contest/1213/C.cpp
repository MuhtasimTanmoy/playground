//https://codeforces.com/contest/1213/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define q(tag, i) cout << endl \
					   << tag << "...." << i << "...." << endl;
using namespace std;
ll dig[11];

void solve()
{
	ll n, m, ans, d;

	cin >> n >> m;
	if (n < m)
		ans = 0LL;
	else
	{
		d = n / m;
		int add = 0;
		m = m % 10;
		for (int i = 0; i < 10; i++)
		{

			if (i != 0)
			{
				add += m;
				if (add > 9)
				{
					add = add % 10;
				}
			}

			dig[i] = add;

			if (i)
				dig[i] += dig[i - 1];
				cout << endl<< "tag "<< "...." << dig[i] << "...." << endl;
		}

		ans = (d / 10) * dig[9];
		ans += dig[d % 10];
	}
	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;

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
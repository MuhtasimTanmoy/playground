//https://codeforces.com/contest/1230/problem/C
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 1; i <= (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

int li[8];
void solve()
{
	int n, m;
	cin >> n >> m;

	int from, to;

	REP(i, 6)
	{
		li[i] = 6;
	}

	li[7]=1;

	int count = 0;
	REP(i, m)
	{
		cin >> from >> to;
		li[from]--;
		li[to]--;
		count++;
	}

	ll sum = 0;
	REP(i, 7)
	{
		cout<<li[i]<<endl;
		sum += li[i];
	}
	if (sum >= 0)
	{
		cout << count << endl;
	}
	else
	{
		cout << count + sum << endl;
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

#ifdef _DEBUG
	cerr << "TIME = " << clock() - tt << endl;
	tt = clock();
#endif

	return 0;
}

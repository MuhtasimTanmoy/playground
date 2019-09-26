//https://codeforces.com/contest/1230/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 1; i < (int)n; i++)
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

void solve()
{
	int n, k;
	cin >> n >> k;

	char ch;

	string result = "";

	if (n <= k)
	{
		result = "";
		REP(i, n + 1)
		{
			cin >> ch;
		}
		result += '0';
		cout << result << endl;
		return;
	}

	cin >> ch;
	if (ch - '1' != 0 && k)
	{
		result += '1';
		k--;
	}
	else
	{
		result += ch;
	}

	REP(i, n)
	{
		cin >> ch;
		if (ch - '0' == 0)
		{
			result += ch;
		}
		else if (k)
		{
			result += '0';
			k--;
		}
		else
		{
			result += ch;
		}
	}

	cout << result << endl;
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

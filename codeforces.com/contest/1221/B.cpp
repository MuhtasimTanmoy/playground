// https://codeforces.com/contest/1221/problem/B
#include <bits/stdc++.h>
#define _DEBUG
#define ll long long
#define pb push_back
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define REP1(i, n) for (int i = 1; i < (int)n; i++)

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second < b.second);
}

char arr[101][101];

void solve()
{
	int n;
	cin >> n;

	bool flag = true;

	// char setIt = 'B';

	REP(i, n)
	{
		REP(j, n)
		{
			if (arr[i][j] == 0)
			{
				arr[i][j] = flag ? 'W' : 'B';
				// setIt = flag ? 'B' : 'W';
				// if (j + 2 < n && i + 1 < n)
				// {
				// 	arr[j + 2][i + 1] = setIt;
				// }
				// if (j + 1 < n & i + 2 < n)
				// {
				// 	arr[j + 1][i + 2] = setIt;
				// }
				// if (j - 1 >= 0 && i + 2 < n)
				// {
				// 	arr[j - 1][i + 2] = setIt;
				// }
				// if (j - 2 >= 0 & i + 1 < n)
				// {
				// 	arr[j - 2][i + 1] = setIt;
				// }
			}
			flag = !flag;
		}
		if(n%2==0)flag=!flag;
	}

	REP(i, n)
	{
		REP(j, n)
		{
			cout << arr[i][j];
		}
		cout << endl;
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

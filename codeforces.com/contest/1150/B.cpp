//https://codeforces.com/contest/1150/problem/B
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

char board[51][51];

void solve()
{
	int n;
	cin >> n;

	int vacantPoint = 0;

	REP(i, n)
	{
		REP(j, n)
		{
			cin >> board[i][j];
			if (board[i][j] == '.')
			{
				vacantPoint++;
			}
		}
	}

	if (vacantPoint % 5)
	{
		cout << "NO" << endl;
		return;
	}


	int possibleTile = vacantPoint / 5;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (board[i][j] == '.')
			{
				if (board[i + 1][j] == '.' && board[i][j + 1] == '.' && board[i - 1][j] == '.' && board[i][j - 1] == '.')
				{
					possibleTile--;
					board[i + 1][j] = '#';
					board[i - 1][j] = '#';
					board[i][j + 1] = '#';
					board[i][j - 1] = '#';
				}
			}
		}
	}


	cout << (possibleTile ? "NO" : "YES") << endl;
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

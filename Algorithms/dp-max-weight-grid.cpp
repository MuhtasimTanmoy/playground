#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 100;
int mat[N][N];
int dp[N][N];

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << mat[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for (int i = 0; i < n; i++)
	{
		dp[i][0] = mat[i][0];
		dp[0][i] = mat[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + mat[i][j];
		}
	}

	cout << dp[n - 1][m - 1] + dp[0][0] << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	// cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}

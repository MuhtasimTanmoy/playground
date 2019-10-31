#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n, m;
	cin >> n >> m;

	int v1, v2, v3, v4;

	int mat[n][m];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	cin >> v1 >> v2 >> v3 >> v4;

	ll total_sum_a = INT32_MIN;
	ll total_sum_b = INT32_MIN;

	ll grand_total_a = 0;
	ll grand_total_b = 0;

	ll sum = 0;
	ll added_sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		added_sum = 0;
		total_sum_a = INT32_MIN;
		for (int j = 0; j < m; j++)
		{
			sum += abs(mat[i][j]);
		}

		for (int j = 0; j < m; j++)
		{
			added_sum += abs(mat[i][j] + v1);
		}

		total_sum_a = max(total_sum_a, sum);
		total_sum_a = max(total_sum_a, added_sum);
		total_sum_a = max(total_sum_a, 1LL * n * v2);
		grand_total_a += total_sum_a;
	}

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		added_sum = 0;
		total_sum_a = INT32_MIN;

		for (int j = 0; j < m; j++)
		{
			sum += mat[j][i];
		}

		for (int j = 0; j < m; j++)
		{
			added_sum += abs(mat[j][i] + v3);
		}

		total_sum_b = max(total_sum_b, sum);
		total_sum_b = max(total_sum_b, added_sum);
		total_sum_b = max(total_sum_b, 1LL * m * v4);
		grand_total_b += total_sum_b;
	}

	cout << max(grand_total_a, grand_total_b) << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}

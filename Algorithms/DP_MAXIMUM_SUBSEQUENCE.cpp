#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int dp[N];

void solve()
{
	int n;
	cin >> n;
	int li[n];

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	dp[0] = 1;

	int _max = INT16_MIN;

	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (li[i] > li[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
		_max = max(dp[i], _max);
	}

	// for (int i = 0; i < n; i++)
	// {
	// 	cout << dp[i] << " ";
	// }

	cout << _max << endl;
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

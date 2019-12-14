#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int dp[100][100];

int coeff(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	else if (dp[n][k])
		return dp[n][k];
	else
		dp[n][k] = coeff(n - 1, k) + coeff(n - 1, k - 1);
	return dp[n][k];
}

void solve()
{
	int n, k;

	cin >> n >> k;

	k = min(k, n - k);

	int res = 1;

	// for (int i = 0; i < k; i++)
	// {
	// 	res *= (n - i);
	// 	res /= (i + 1);
	// }

	// cout << res << endl;

	cout << coeff(n, min(k, n - k)) << endl;
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

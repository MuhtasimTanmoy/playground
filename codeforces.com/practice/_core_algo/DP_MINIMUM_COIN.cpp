#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

int n, target;
vector<int> li;
int cache;
int dp[N];
int seq[N];
int possible_min;

int get_min_coin(int t)
{
	if (dp[t])
		return dp[t];
	if (t < 0)
		return 10000;
	else if (t == 0)
		return 0;
	else
	{
		int best = INT32_MAX;
		for (int a : li)
		{
			int calculate = get_min_coin(t - a) + 1;
			best = min(best, calculate);
			dp[t] = best;
		}
		return best;
	}
}

int get_min_coin_iterative(int t)
{
	dp[0] = 0;
	int best = INT32_MAX;
	for (int i = 1; i <= t; i++)
	{
		best = 1000;

		for (auto x : li)
		{
			if (i - x >= 0 && best)
			{
				possible_min = dp[i - x] + 1;

				best = min(best, possible_min);

				if (best == possible_min)
				{
					seq[i] = x;
				}
			}
		}
		dp[i] = best;
	}
}

void solve()
{
	cin >> n >> target;
	int holder;
	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		li.push_back(holder);
	}
	// cout << get_min_coin(target) << endl;
	get_min_coin_iterative(target);

	int t = target;

	while (t > 0)
	{
		cout << seq[t];
		t -= seq[t];
	}
	cout << endl;
	cout << dp[target] << endl;
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

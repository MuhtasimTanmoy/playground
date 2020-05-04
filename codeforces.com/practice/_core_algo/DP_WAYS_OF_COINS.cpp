#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
vector<int> li;
int dp[N];

int ways_to_target(int target)
{
	dp[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		for (auto x : li)
		{
			if (i - x >= 0)
			{
				dp[i] += dp[i - x];
			}
		}
	}

	return dp[target];
}

void solve()
{
	int n, target;
	cin >> n >> target;
	int holder;
	
	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		li.push_back(holder);
	}

	cout << ways_to_target(target) << endl;
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

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
	int no_of_soaps;
	cin >> no_of_soaps;

	vector<int> prices(no_of_soaps);
	for (int i = 0; i < no_of_soaps; i++)
	{
		cin >> prices[i];
	}

	sort(prices.begin(), prices.end());

	int query;
	cin >> query;

	int less_then;

	while (query--)
	{
		cin >> less_then;
		int lo = 0, hi = no_of_soaps - 1;
		int mid = 0;

		int result = -1;

		while (lo <= hi)
		{
			mid = (lo + hi) >> 1;

			if (prices[mid] == less_then)
			{
				result = mid;
				hi = mid - 1;
			}
			else if (prices[mid] < less_then)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}

		cout << (result == -1 ? lo : result) << endl;
	}
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

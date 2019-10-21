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
	int lo, hi;
	cin >> lo >> hi;
	vector<int> prime;
	int limit = floor(sqrt(hi));
	int loLim=0;
	bool mark[limit] = {false};
	bool mark_nums[hi - lo + 1] = {false};

	for (int i = 2; i <= limit; i++)
	{
		if (!mark[i])
		{
			prime.push_back(i);
			for (int j = i; j <= limit; j += i)
			{
				mark[j] = true;
			}
		}
	}

	for (int i = 0; i < prime.size(); i++)
	{
		loLim = floor(lo / prime[i]) * prime[i];

		if (loLim == 0 || loLim < lo)
		{
			loLim += prime[i];
		}

		for (int j = loLim; j <= hi; j += prime[i])
		{
			mark[j - lo] = true;
		}
	}

	for (int i = lo; i <= hi; i++)
	{
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases;
	cin >> no_of_test_cases;
	// no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}

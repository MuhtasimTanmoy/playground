//https://1312/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// QUERY > Why this ll worked

const int N = 2e5 + 11;
ll l[N];
bool solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> l[i];
	}

	set<int> uset;

	ll x;
	for (int i = 0; i < n; i++)
	{

		x = l[i];

		int d = 0;

		while (x)
		{
			if ((x % k) > 1)
			{
				return false;
			}

			if (x % k == 1)
			{
				if (uset.count(d))
				{
					return false;
				}

				uset.insert(d);
			}

			d++;
			x = x / k;
		}
	}

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(0);
	cout.tie(0);
	int no_of_test_cases = 0;
	cin >> no_of_test_cases;
	if (!no_of_test_cases)
		no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		cout << (solve() ? "YES" : "NO") << endl;
	}

	return 0;
}

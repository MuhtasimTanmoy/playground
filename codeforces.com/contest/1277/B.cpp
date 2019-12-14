//https://codeforces.com/contest/1277/problem/B
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin >> n;
	int li[n];

	set<int, greater<int>> _set;
	set<int, greater<int>>::iterator itr;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
		if (li[i] % 2 == 0)
		{
			_set.insert(li[i]);
		}
	}

	int count = 0;

	int elem = 0;

	while (!_set.empty())
	{
		itr = _set.begin();

		elem = *itr;

		while (1)
		{
			_set.erase(elem);

			elem = elem >> 1;

			count++;

			if ((elem) % 2 == 0)
			{
				_set.insert(elem);
			}
			else
			{
				break;
			}
		}
	}

	cout << count << endl;
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

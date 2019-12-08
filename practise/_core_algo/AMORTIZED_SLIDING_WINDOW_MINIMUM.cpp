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
	int n, sliding_window;
	cin >> n >> sliding_window;

	int li[n];
	deque<int> stk;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	for (int i = 0; i < sliding_window; i++)
	{
		if (stk.empty())
		{
			stk.push_back(li[i]);
		}
		else
		{
			while (!stk.empty() && stk.back() >= li[i])
			{
				stk.pop_back();
			}
			stk.push_back(li[i]);
		}
	}

	cout << stk.front() << " ";

	for (int i = sliding_window; i < n; i++)
	{
		if (li[i - sliding_window] == stk.front())
		{
			stk.pop_front();
		}
		if (stk.empty())
		{
			stk.push_back(li[i]);
		}
		else
		{
			while (!stk.empty() && stk.back() >= li[i])
			{
				stk.pop_back();
			}
			stk.push_back(li[i]);
		}

		cout << stk.front() << " ";
	}
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

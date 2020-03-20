#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

// https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

const int N = 2e5 + 11;

void solve()
{
	int n;
	cin >> n ;

	stack<int> stk;

	int li[n];
	int less[n];

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (stk.empty())
		{
			stk.push(li[i]);
			less[i] = -1;
		}
		else
		{
			while (!stk.empty() && stk.top() >= li[i])
			{
				stk.pop();
			}

			if (stk.empty())
			{
				less[i] = -1;
			}
			else
			{
				less[i] = stk.top();
			}

			stk.push(li[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << less[i] << " ";
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

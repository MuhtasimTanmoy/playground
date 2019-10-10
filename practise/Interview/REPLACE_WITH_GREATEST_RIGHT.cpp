#include <bits/stdc++.h>
#define _DEBUG
using namespace std;

const int MAX = 1e7 + 1;
long long li[MAX];

void solve()
{
	// https://www.geeksforgeeks.org/replace-every-element-with-the-greatest-on-right-side/
	int n;
	cin >> n;

	int holder;
	vector<int> li(n);

	for (int i = 0; i < n; i++)
	{
		cin >> holder;
		li[i] = holder;
	}

	int current = -1;
	int nextMax = -1;

	for (int i = n - 1; i >= 0; i--)
	{
		current = max(nextMax, current);
		nextMax = max(nextMax, li[i]);
		li[i] = current;
	}

	for (int i = 0; i < n; i++)
	{
		cout << li[i] << " ";
	}
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	ios_base::sync_with_stdio(false);
	int no_of_test_cases;
	// cin >> no_of_test_cases;
	no_of_test_cases = 1;
	while (no_of_test_cases--)
	{
		solve();
	}

	return 0;
}

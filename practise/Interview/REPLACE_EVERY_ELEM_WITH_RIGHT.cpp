#include <bits/stdc++.h>
#define _DEBUG
using namespace std;

const int MAX = 1e7 + 1;
long long li[MAX];

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	int start = 0;
	int end = n - 1;

	int diff = -1;

	while (start < end)
	{
		if (li[start] <= li[end])
		{
			diff = end - start;
			break;
		}
		else
		{
			if ((li[start] - li[start + 1]) > (li[end - 1] - li[end]))
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}

	cout << diff << endl;
}

void solve_geek_for_geeks()
{
	// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
}

void solve2()
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
		// solve();
		// solve_geek_for_geeks()
		solve2();
	}

	return 0;
}

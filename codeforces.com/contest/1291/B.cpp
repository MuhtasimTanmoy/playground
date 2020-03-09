//https://1291/problem/B
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

	vector<int> li(n);

	for (int i = 0; i < n; i++)
	{
		cin >> li[i];
	}

	int max_possible = -1;

	int distance = 1;

	int i;

	int snapshot = n;
	for (i = 0; i < n; i++)
	{
		max_possible = max_possible + distance;
		if (li[i] < max_possible)
		{
			snapshot = i;
			break;
		}
	}
	max_possible = max(li[i - 1], max_possible - 1);
	distance = -1;

	for (i = snapshot; i < n; i++)
	{
		max_possible = min(max_possible + distance,li[i]);
		if (max_possible < 0)
			break;
	}

	if (i == n)
		cout << "Yes" << endl;
	else
	{
		cout << "No" << endl;
	}
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
		solve();
	}

	return 0;
}

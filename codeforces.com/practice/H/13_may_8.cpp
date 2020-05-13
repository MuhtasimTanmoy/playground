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

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int dis = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 1; j < n; j++)
		{
			if (v[j - 1] > v[j])
			{
				dis = abs(v[j - 1] - v[j]);
				v[j - 1] -= dis;
				v[j] += dis;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
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

//https://1217/problem/C
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
	string s;
	cin >> n >> s;

	pair<int, int> coordinate(0,0);

	for (int j = 0; j < n - 1; j++)
	{
		coordinate.first = 0;
		coordinate.second = 0;

		for (int i = j; i < n; i++)
		{
			if (s[i] == 'L')
			{
				coordinate.first += 1;
			}
			else if (s[i] == 'R')
			{
				coordinate.first -= 1;
			}
			else if (s[i] == 'U')
			{
				coordinate.second += 1;
			}
			else
			{
				coordinate.second -= 1;
			}

			if (coordinate.first == 0 && coordinate.second == 0)
			{
				cout << j + 1 << " " << i + 1 << endl;
				return;
			}
		}
	}

	cout << -1 << endl;
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

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 10;
int _count = 0;
int n;

int mat[N];
int diag[N];
int diag_inv[N];

void find_ways_queen(int k)
{
	if (k == n)
	{
		_count++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (mat[i] || diag[i + k] || diag_inv[i - k + n - 1])
			{
				continue;
			}
			mat[i] = diag[i + k] = diag_inv[i - k + n - 1] = 1;
			find_ways_queen(k + 1);
			mat[i] = diag[i + k] = diag_inv[i - k + n - 1] = 0;
		}
	}
}

void solve()
{
	cin >> n;
	find_ways_queen(0);
	cout << _count << endl;
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

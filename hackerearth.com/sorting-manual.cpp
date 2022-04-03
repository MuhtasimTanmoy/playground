#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;

//SORTING

void solve()
{
	int count = 0;
	int temp = 0;
	int c[N];
	for (int j = 0; j < count; j++)
	{
		for (int k = 0; k < j; k++)
		{
			if (c[j] > c[k])
			{
				temp = c[j];
				c[j] = c[k];
				c[k] = temp;
			}
		}
	}
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
